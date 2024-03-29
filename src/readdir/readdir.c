/* -*- Mode: C -*- */
/*=============================================================================*\
 * File: readdir.c
 * Author: Bryan Jurish <moocow@ling.uni-potsdam.de>
 * Description: general directory access object
 *
 * Copyright (c) 2003-2009 Bryan Jurish.
 *
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * See file LICENSE for further informations on licensing terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *=============================================================================*/
 
/* 
   Note - this source has modifications made specifically for the Organelle
   Synth. - Michael Spears, Feb. 2024
*/

#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include <m_pd.h>

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

/*--------------------------------------------------------------------
 * DEBUG
 *--------------------------------------------------------------------*/
//#define READDIR_DEBUG 1


/*=====================================================================
 * Constants
 *=====================================================================*/
#ifdef READDIR_DEBUG
// error-message buffer
#define EBUFSIZE 256
static char readdir_organelle_errbuf[EBUFSIZE];
#endif

/*=====================================================================
 * Structures and Types
 *=====================================================================*/

// static char *readdir_banner =
//   "\n"
//   "readdir: simple directory accessor v" PACKAGE_VERSION " by Bryan Jurish\n"
//   "readdir: compiled by " PACKAGE_BUILD_USER " on " PACKAGE_BUILD_DATE ;

static t_class *readdir_organelle_class;

typedef struct _readdir_organelle
{
  t_object       x_obj;
  DIR           *x_dir;         //-- current directory
  t_symbol      *x_dirname;     //-- current directory name
  //struct dirent *x_dirent;      //-- current entry of current directory
  t_atom         x_eatom;       //-- current output atom (symbol)
  t_outlet      *x_ent_outlet;  //-- entry outlet
  t_outlet      *x_eod_outlet;  //-- end-of-directory outlet
} t_readdir_organelle;

/*=====================================================================
 * Constants
 *=====================================================================*/
static t_symbol *sp_none;
static t_symbol *sp_unknown;
static t_symbol *sp_file;
static t_symbol *sp_dir;
static t_symbol *sp_fifo;
static t_symbol *sp_sock;
static t_symbol *sp_chrdev;
static t_symbol *sp_blkdev;

/*--------------------------------------------------------------------
 * close
 */
static void readdir_organelle_close(t_readdir_organelle *x)
{
  if (!x->x_dir) return;
  if (0 != closedir(x->x_dir)) {
    pd_error(x, "readdir_organelle: cannot close %s: %s", x->x_dirname->s_name, strerror(errno));
    return;
  }
  x->x_dir = NULL;
  x->x_dirname = sp_none;
}

/*--------------------------------------------------------------------
 * open DIR
 */
static void readdir_organelle_open(t_readdir_organelle *x, t_symbol *dirname)
{
#ifdef READDIR_DEBUG
  post("readdir_organelle: got message: open %s", dirname->s_name);
#endif

  if (x->x_dir) readdir_organelle_close(x);
  if ( !(x->x_dir = opendir(dirname->s_name)) ) {
    pd_error(x, "readdir_organelle: cannot open %s: %s", dirname->s_name, strerror(errno));
    return;
  }
  x->x_dirname = dirname;
}

/*--------------------------------------------------------------------
 * next : get next entry
 */
static void readdir_organelle_next(t_readdir_organelle *x)
{
  t_symbol *sel = sp_unknown;
  struct dirent *result = NULL;
  if ( !x->x_dir || !(result = readdir(x->x_dir)) ) {
    if (errno == EBADF) {
      //-- real error
      pd_error(x, "readdir_organelle: cannot read from %s: %s", x->x_dirname->s_name, strerror(errno));
    }
    else {
      //-- end of directory
      outlet_bang(x->x_eod_outlet);
    }
    return;
  }

  switch (result->d_type)
    {
    case DT_REG: sel = sp_file; break;

    case DT_DIR: sel = sp_dir; break;

    case DT_FIFO: sel = sp_fifo; break;



    case DT_SOCK: sel = sp_sock; break;



    case DT_CHR: sel = sp_chrdev; break;



    case DT_BLK: sel = sp_blkdev; break;



    case DT_UNKNOWN:

    default:
      sel = sp_unknown;
      break;
    }




  x->x_eatom.a_w.w_symbol = gensym(result->d_name);
  outlet_anything(x->x_ent_outlet, sel, 1, &x->x_eatom);
}

/*--------------------------------------------------------------------
 * rewind
 */
static void readdir_organelle_rewind(t_readdir_organelle *x)
{
  if (x->x_dir) rewinddir(x->x_dir);
}

/*--------------------------------------------------------------------
 * tell
 */
static void readdir_organelle_tell(t_readdir_organelle *x)
{
  off_t off = 0;
  if (x->x_dir) off = telldir(x->x_dir);
#ifdef READDIR_DEBUG
  post("readdir_organelle_tell(): off: %%d=%d, %%f=%f\n", off, (t_float)off);
#endif
  outlet_float(x->x_ent_outlet, (t_float)off);
}

/*--------------------------------------------------------------------
 * seek FLOAT
 */
static void readdir_organelle_seek(t_readdir_organelle *x, t_floatarg pos)
{
  if (!x->x_dir) {
    pd_error(x, "readdir_organelle: seek %g: no directory opened!", pos);
    return;
  }
  seekdir(x->x_dir, (off_t)pos);
}


/*--------------------------------------------------------------------
 * new
 */
static void *readdir_organelle_new(void)
{
    t_readdir_organelle *x = (t_readdir_organelle *)pd_new(readdir_organelle_class);

    //-- defaults
    x->x_dir = NULL;
    x->x_dirname = sp_none;
    SETSYMBOL(&x->x_eatom, sp_none);

    //-- outlets
    x->x_ent_outlet = outlet_new(&x->x_obj, &s_symbol);
    x->x_eod_outlet = outlet_new(&x->x_obj, &s_bang);

    return (void *)x;
}

/*--------------------------------------------------------------------
 * free
 */
static void readdir_organelle_free(t_readdir_organelle *x)
{
  readdir_organelle_close(x);
  outlet_free(x->x_ent_outlet);
  outlet_free(x->x_eod_outlet);
  return;
}

/*--------------------------------------------------------------------
 * setup
 */
void readdir_organelle_setup(void)
{
  // post(readdir_banner);
#ifdef READDIR_DEBUG
  post("readdir_organelle: debugging enabled");
#endif

  //-- constants
  sp_none = gensym("none");
  sp_unknown = gensym("unknown");
  sp_file = gensym("file");
  sp_dir = gensym("dir");
  sp_fifo = gensym("fifo");
  sp_sock = gensym("sock");
  sp_chrdev = gensym("chrdev");
  sp_blkdev = gensym("blkdev");

  //-- class
  readdir_organelle_class = class_new(gensym("readdir_organelle"),
			    (t_newmethod)readdir_organelle_new,
			    (t_method)readdir_organelle_free,
			    sizeof(t_readdir_organelle),
			    CLASS_DEFAULT,
			    0);
  
  //-- methods
  class_addmethod(readdir_organelle_class, (t_method)readdir_organelle_open, gensym("open"), A_DEFSYMBOL, 0);
  class_addmethod(readdir_organelle_class, (t_method)readdir_organelle_close, gensym("close"), 0);
  class_addmethod(readdir_organelle_class, (t_method)readdir_organelle_next, gensym("next"), 0);
  class_addbang(readdir_organelle_class, (t_method)readdir_organelle_next);
  class_addmethod(readdir_organelle_class, (t_method)readdir_organelle_rewind, gensym("rewind"), 0);
  class_addmethod(readdir_organelle_class, (t_method)readdir_organelle_tell, gensym("tell"), 0);
  class_addmethod(readdir_organelle_class, (t_method)readdir_organelle_seek, gensym("seek"), A_DEFFLOAT, 0);
  
  //-- help symbol
  // class_sethelpsymbol(readdir_class, gensym("readdir-help.pd"));
}
