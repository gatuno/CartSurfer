# Automake file for Cart Surfer

gamedatadir = $(pkgdatadir)/data

bin_PROGRAMS = cart-surfer
cart_surfer_SOURCES = cartsurfer.c
#EXTRA_DIST =

cart_surfer_CPPFLAGS = -DGAMEDATA_DIR=\"$(gamedatadir)/\" -DLOCALEDIR=\"$(localedir)\" $(AM_CPPFLAGS)
cart_surfer_CFLAGS = $(SDL2_CFLAGS) $(SDL2_image_CFLAGS) $(AM_CFLAGS)
cart_surfer_LDADD = $(SDL2_LIBS) $(SDL2_image_LIBS) $(SDL2_mixer_LIBS)

