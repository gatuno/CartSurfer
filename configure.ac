AC_INIT([Cart Surfer], [0.1], [], [cart-surfer])

AC_REVISION([Revision 1])

AC_CONFIG_AUX_DIR([build-aux])

AC_CONFIG_SRCDIR([src/cartsurfer.c])

# For debian systems, /usr as default
AC_PREFIX_DEFAULT([/usr])

# We need Gcc
AC_PROG_CC

# and automake
AM_INIT_AUTOMAKE([-Wall -Werror])

AM_PROG_CC_C_O

# Check for pkg-config
PKG_PROG_PKG_CONFIG

SDL2_VERSION=2.0.0
SDL2_IMAGE_VERSION=2.0.0
SDL2_MIXER_VERSION=2.0.0
SDL2_TTF_VERSION=2.0.12

AC_MSG_CHECKING([if you have SDL2 installed on your system])
PKG_CHECK_EXISTS([sdl2 >= $SDL2_VERSION], [AC_MSG_RESULT([yes])], [AC_MSG_FAILURE([SDL2 not found in your system])])
PKG_CHECK_MODULES(SDL2, [sdl2 >= $SDL2_VERSION], [], [])

AC_MSG_CHECKING([if you have SDL2_image installed on your system])
PKG_CHECK_EXISTS([SDL2_image >= $SDL2_IMAGE_VERSION], [AC_MSG_RESULT([yes])], [AC_MSG_FAILURE([SDL2_image not found in your system])])
PKG_CHECK_MODULES(SDL2_image, [SDL2_image >= $SDL2_IMAGE_VERSION], [], [])

AC_MSG_CHECKING([if you have SDL2_mixer installed on your system])
PKG_CHECK_EXISTS([SDL2_mixer >= $SDL2_MIXER_VERSION], [AC_MSG_RESULT([yes])], [AC_MSG_FAILURE([SDL2_mixer not found in your system])])
PKG_CHECK_MODULES(SDL2_mixer, [SDL2_mixer >= $SDL2_MIXER_VERSION], [], [])

# Aún no necesito la SDL TTF
#AC_MSG_CHECKING([if you have SDL2_ttf installed on your system])
#PKG_CHECK_EXISTS([SDL2_ttf >= $SDL_TTF_VERSION], [AC_MSG_RESULT([yes])], [AC_MSG_FAILURE([SDL2_ttf not found in your system])])
#PKG_CHECK_MODULES(SDL2_ttf, [SDL2_ttf >= $SDL2_TTF_VERSION], [], [])

AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_HOST

AC_CONFIG_FILES([
                 Makefile
                 src/Makefile
                 data/Makefile
])

AC_OUTPUT
