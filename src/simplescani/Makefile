

# change this to match the name of the external you would like to generate

lib.name = simplescani


$(lib.name).class.sources = simplescani.c


suppress-wunused = yes

define forDarwin
  cflags += -DMSP_ON_CLANG -DGENLIB_USE_FLOAT32 -mmacosx-version-min=10.9
endef


# datafiles =
# datafiles and datadirs:
# All extra files you want to include in binary distributions of the
# library: abstractions and help patches, example patches, meta patch, readme
# and license texts, manuals, sound files, etcetera. Use 'datafiles' for all
# files that should go into your lib rootdir and 'datadirs' for complete
# directories you want to copy from source to distribution.

include ./pd-lib-builder/Makefile.pdlibbuilder