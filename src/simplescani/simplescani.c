/* -*- Mode: C -*- */


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <m_pd.h>



static t_class *simplescani_class;

typedef struct _simplescani
{
  t_object       x_obj;
  
  t_symbol      *x_prefix; 
  t_outlet      *x_num_outlet;  //-- scanned num outlet
  t_outlet      *x_null_outlet;
} t_simplescani;

static void simplescani_symbol(t_simplescani *x, t_symbol *s)
{
    int num = 0;
    char *pattern;
    size_t prefixLen = strlen(x->x_prefix->s_name);
    pattern = malloc((prefixLen + 2)*sizeof(char));
    sprintf(pattern,"%s%%d",x->x_prefix->s_name);
    
    int c = sscanf(s->s_name, pattern, &num);
    
    if (c == 0) {
      outlet_bang(x->x_null_outlet);
      free(pattern);
      return;
    }
    
    outlet_float(x->x_num_outlet, num);
    
    free(pattern);
}

/*--------------------------------------------------------------------
 * new
 */
static void *simplescani_new(t_symbol *s, int argc, t_atom *argv)
{
    t_simplescani *x = (t_simplescani *)pd_new(simplescani_class);

    x->x_prefix = gensym("");
    
    
    switch(argc){
    default:
    case 1:
      x->x_prefix=atom_getsymbol(argv);
      break;
    case 0:
      break;
    }

    //-- outlets
    x->x_num_outlet = outlet_new(&x->x_obj, &s_float);
    x->x_null_outlet = outlet_new(&x->x_obj, &s_bang);

    return (void *)x;
}

/*--------------------------------------------------------------------
 * free
 */
static void simplescani_free(t_simplescani *x)
{
  
  outlet_free(x->x_num_outlet);
  outlet_free(x->x_null_outlet);
  return;
}

/*--------------------------------------------------------------------
 * setup
 */
void simplescani_setup(void)
{
 
  
  simplescani_class = class_new(gensym("simplescani"),
			    (t_newmethod)simplescani_new,
			    (t_method)simplescani_free,
			    sizeof(t_simplescani),
			    CLASS_DEFAULT,
			    A_GIMME, 0);
  
  class_addsymbol(simplescani_class, (t_method)simplescani_symbol);

}
