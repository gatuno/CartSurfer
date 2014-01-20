/*
 * cartsurfer.c
 * This file is part of Cart Surfer
 *
 * Copyright (C) 2014 - Félix Arreola Rodríguez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* ----------------
 * LEGAL NOTICE
 * ----------------
 *
 * This game is NOT related to Club Penguin in any way. Also,
 * this game is not intended to infringe copyrights, the graphics and
 * sounds used are Copyright of Disney.
 *
 * The new SDL code is written by Gatuno, and is released under
 * the term of the GNU General Public License.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define FPS (1000/18)

#define RANDOM(x) ((int) (x ## .0 * rand () / (RAND_MAX + 1.0)))

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE !FALSE
#endif

/* Enumerar las imágenes */
enum {
	IMG_SEG1_1,
	IMG_SEG1_2,
	IMG_SEG1_3,
	IMG_SEG1_4,
	IMG_SEG1_5,
	IMG_SEG1_6,
	IMG_SEG1_7,
	IMG_SEG1_8,
	IMG_SEG1_9,
	IMG_SEG1_10,
	IMG_SEG1_11,
	IMG_SEG1_12,
	IMG_SEG1_13,
	IMG_SEG1_14,
	IMG_SEG1_15,
	IMG_SEG1_16,
	IMG_SEG1_17,
	IMG_SEG1_18,
	IMG_SEG1_19,
	IMG_SEG1_20,
	IMG_SEG1_21,
	IMG_SEG1_22,
	IMG_SEG1_23,
	IMG_SEG1_24,
	IMG_SEG1_25,
	IMG_SEG1_26,
	IMG_SEG1_27,
	IMG_SEG1_28,
	IMG_SEG1_29,
	IMG_SEG1_30,
	IMG_SEG1_31,
	IMG_SEG1_32,
	IMG_SEG1_33,
	IMG_SEG1_34,
	IMG_SEG1_35,
	IMG_SEG1_36,
	IMG_SEG1_37,
	IMG_SEG1_38,
	IMG_SEG1_39,
	IMG_SEG1_40,
	IMG_SEG1_41,
	IMG_SEG1_42,
	IMG_SEG1_43,
	IMG_SEG1_44,
	IMG_SEG1_45,
	IMG_SEG1_46,
	IMG_SEG1_47,
	IMG_SEG1_48,
	
	IMG_SEG2_1,
	IMG_SEG2_2,
	IMG_SEG2_3,
	IMG_SEG2_4,
	IMG_SEG2_5,
	IMG_SEG2_6,
	IMG_SEG2_7,
	IMG_SEG2_8,
	IMG_SEG2_9,
	IMG_SEG2_10,
	IMG_SEG2_11,
	IMG_SEG2_12,
	IMG_SEG2_13,
	IMG_SEG2_14,
	IMG_SEG2_15,
	IMG_SEG2_16,
	IMG_SEG2_17,
	IMG_SEG2_18,
	IMG_SEG2_19,
	IMG_SEG2_20,
	IMG_SEG2_21,
	IMG_SEG2_22,
	IMG_SEG2_23,
	IMG_SEG2_24,
	IMG_SEG2_25,
	
	IMG_SEG3_1,
	IMG_SEG3_2,
	IMG_SEG3_3,
	IMG_SEG3_4,
	IMG_SEG3_5,
	IMG_SEG3_6,
	IMG_SEG3_7,
	IMG_SEG3_8,
	IMG_SEG3_9,
	IMG_SEG3_10,
	IMG_SEG3_11,
	IMG_SEG3_12,
	IMG_SEG3_13,
	IMG_SEG3_14,
	IMG_SEG3_15,
	IMG_SEG3_16,
	IMG_SEG3_17,
	IMG_SEG3_18,
	IMG_SEG3_19,
	IMG_SEG3_20,
	IMG_SEG3_21,
	IMG_SEG3_22,
	IMG_SEG3_23,
	IMG_SEG3_24,
	IMG_SEG3_25,
	
	IMG_SEG4_1,
	IMG_SEG4_2,
	IMG_SEG4_3,
	IMG_SEG4_4,
	IMG_SEG4_5,
	IMG_SEG4_6,
	IMG_SEG4_7,
	IMG_SEG4_8,
	IMG_SEG4_9,
	IMG_SEG4_10,
	IMG_SEG4_11,
	IMG_SEG4_12,
	IMG_SEG4_13,
	IMG_SEG4_14,
	IMG_SEG4_15,
	IMG_SEG4_16,
	IMG_SEG4_17,
	IMG_SEG4_18,
	IMG_SEG4_19,
	IMG_SEG4_20,
	IMG_SEG4_21,
	IMG_SEG4_22,
	IMG_SEG4_23,
	IMG_SEG4_24,
	IMG_SEG4_25,
	IMG_SEG4_26,
	IMG_SEG4_27,
	IMG_SEG4_28,
	IMG_SEG4_29,
	IMG_SEG4_30,
	IMG_SEG4_31,
	IMG_SEG4_32,
	IMG_SEG4_33,
	IMG_SEG4_34,
	IMG_SEG4_35,
	IMG_SEG4_36,
	IMG_SEG4_37,
	IMG_SEG4_38,
	IMG_SEG4_39,
	IMG_SEG4_40,
	IMG_SEG4_41,
	IMG_SEG4_42,
	IMG_SEG4_43,
	IMG_SEG4_44,
	IMG_SEG4_45,
	IMG_SEG4_46,
	IMG_SEG4_47,
	IMG_SEG4_48,
	
	IMG_SEG5_1,
	IMG_SEG5_2,
	IMG_SEG5_3,
	IMG_SEG5_4,
	IMG_SEG5_5,
	IMG_SEG5_6,
	IMG_SEG5_7,
	IMG_SEG5_8,
	IMG_SEG5_9,
	IMG_SEG5_10,
	IMG_SEG5_11,
	IMG_SEG5_12,
	IMG_SEG5_13,
	IMG_SEG5_14,
	IMG_SEG5_15,
	IMG_SEG5_16,
	IMG_SEG5_17,
	IMG_SEG5_18,
	IMG_SEG5_19,
	IMG_SEG5_20,
	IMG_SEG5_21,
	IMG_SEG5_22,
	IMG_SEG5_23,
	IMG_SEG5_24,
	IMG_SEG5_25,
	IMG_SEG5_26,
	IMG_SEG5_27,
	IMG_SEG5_28,
	IMG_SEG5_29,
	IMG_SEG5_30,
	IMG_SEG5_31,
	IMG_SEG5_32,
	IMG_SEG5_33,
	IMG_SEG5_34,
	IMG_SEG5_35,
	IMG_SEG5_36,
	IMG_SEG5_37,
	IMG_SEG5_38,
	IMG_SEG5_39,
	IMG_SEG5_40,
	IMG_SEG5_41,
	IMG_SEG5_42,
	IMG_SEG5_43,
	IMG_SEG5_44,
	IMG_SEG5_45,
	IMG_SEG5_46,
	IMG_SEG5_47,
	IMG_SEG5_48,
	
	IMG_SEG6_1,
	IMG_SEG6_2,
	IMG_SEG6_3,
	IMG_SEG6_4,
	IMG_SEG6_5,
	IMG_SEG6_6,
	IMG_SEG6_7,
	IMG_SEG6_8,
	IMG_SEG6_9,
	IMG_SEG6_10,
	IMG_SEG6_11,
	IMG_SEG6_12,
	IMG_SEG6_13,
	IMG_SEG6_14,
	IMG_SEG6_15,
	IMG_SEG6_16,
	IMG_SEG6_17,
	IMG_SEG6_18,
	IMG_SEG6_19,
	IMG_SEG6_20,
	IMG_SEG6_21,
	IMG_SEG6_22,
	IMG_SEG6_23,
	IMG_SEG6_24,
	IMG_SEG6_25,
	IMG_SEG6_26,
	IMG_SEG6_27,
	
	NUM_IMAGES
};

const char *images_names[NUM_IMAGES] = {
	GAMEDATA_DIR "images/Fondo-seg-1_0001.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0002.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0003.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0004.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0005.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0006.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0007.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0008.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0009.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0010.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0011.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0012.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0013.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0014.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0015.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0016.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0017.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0018.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0019.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0020.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0021.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0022.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0023.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0024.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0025.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0026.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0027.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0028.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0029.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0030.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0031.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0032.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0033.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0034.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0035.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0036.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0037.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0038.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0039.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0040.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0041.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0042.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0043.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0044.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0045.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0046.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0047.png",
	GAMEDATA_DIR "images/Fondo-seg-1_0048.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0001.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0002.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0003.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0004.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0005.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0006.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0007.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0008.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0009.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0010.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0011.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0012.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0013.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0014.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0015.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0016.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0017.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0018.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0019.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0020.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0021.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0022.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0023.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0024.png",
	GAMEDATA_DIR "images/Fondo-seg-2_0025.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0001.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0002.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0003.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0004.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0005.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0006.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0007.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0008.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0009.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0010.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0011.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0012.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0013.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0014.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0015.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0016.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0017.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0018.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0019.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0020.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0021.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0022.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0023.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0024.png",
	GAMEDATA_DIR "images/Fondo-seg-3_0025.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0001.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0002.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0003.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0004.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0005.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0006.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0007.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0008.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0009.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0010.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0011.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0012.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0013.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0014.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0015.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0016.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0017.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0018.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0019.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0020.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0021.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0022.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0023.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0024.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0025.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0026.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0027.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0028.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0029.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0030.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0031.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0032.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0033.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0034.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0035.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0036.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0037.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0038.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0039.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0040.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0041.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0042.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0043.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0044.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0045.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0046.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0047.png",
	GAMEDATA_DIR "images/Fondo-seg-4_0048.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0001.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0002.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0003.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0004.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0005.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0006.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0007.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0008.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0009.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0010.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0011.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0012.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0013.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0014.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0015.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0016.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0017.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0018.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0019.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0020.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0021.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0022.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0023.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0024.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0025.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0026.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0027.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0028.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0029.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0030.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0031.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0032.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0033.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0034.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0035.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0036.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0037.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0038.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0039.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0040.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0041.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0042.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0043.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0044.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0045.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0046.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0047.png",
	GAMEDATA_DIR "images/Fondo-seg-5_0048.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0001.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0002.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0003.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0004.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0005.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0006.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0007.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0008.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0009.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0010.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0011.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0012.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0013.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0014.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0015.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0016.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0017.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0018.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0019.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0020.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0021.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0022.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0023.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0024.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0025.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0026.png",
	GAMEDATA_DIR "images/Fondo-seg-6_0027.png"
};

/* Los automátas */
static const int fondo_inicio [7] = {
	-1,
	IMG_SEG1_1,
	IMG_SEG2_1,
	IMG_SEG3_1,
	IMG_SEG4_1,
	IMG_SEG5_1,
	IMG_SEG6_1
};

static const int fondo_topframes [7] = {
	-1,
	47,
	24,
	24,
	47,
	47,
	26
};

/* Codigos de salida */
enum {
	GAME_NONE = 0, /* No usado */
	GAME_CONTINUE,
	GAME_QUIT
};

static const int mine_holder [5][31] = {
	{1, 1, 4, 2, 1, 5, 3, 1, 1, 4, 2, 5, 3, 1, 1, 1, 4, 2, 4, 2, 1, 1, 5, 3, 5, 3, 1, 1, 6, -1},
	{1, 1, 5, 3, 1, 4, 2, 5, 3, 1, 4, 2, 1, 1, 1, 4, 2, 1, 5, 3, 4, 2, 1, 1, 5, 3, 1, 1, 6, -1},
	{1, 1, 1, 5, 3, 1, 1, 1, 4, 2, 1, 4, 2, 1, 5, 3, 4, 2, 1, 5, 3, 1, 4, 2, 5, 3, 1, 1, 6, -1},
	{1, 1, 5, 3, 1, 4, 2, 1, 1, 4, 2, 1, 5, 3, 1, 4, 2, 5, 3, 5, 3, 1, 1, 4, 2, 4, 2, 1, 1, 6, -1},
	{1, 1, 1, 5, 3, 4, 2, 1, 4, 2, 1, 1, 5, 3, 1, 5, 3, 4, 2, 1, 5, 3, 1, 1, 4, 2, 1, 1, 6, -1}
};

/* Estructuras */

/* Prototipos de función */
int game_loop (void);
void setup (void);

/* Variables globales */
SDL_Window * window;
SDL_Surface *screen;
SDL_Surface * images [NUM_IMAGES];
int fondo_frame = 0;
int last_safe_seg = 0;
int current_seg = 0;
int mine_array [31];

int main (int argc, char *argv[]) {
	int seg;
	
	setup ();
	seg = RANDOM(5);
	printf ("Eligiendo mina: %i\n", seg);
	memcpy (mine_array, mine_holder[seg], sizeof (mine_array));
	
	do {
		if (game_loop () == GAME_QUIT) break;
	} while (1 == 0);

	SDL_Quit ();
	return EXIT_SUCCESS;
}

int game_loop (void) {
	int done = 0;
	SDL_Event event;
	SDL_Keycode key;
	Uint32 last_time, now_time;
	SDL_Rect rect;
	
	SDL_EventState (SDL_MOUSEMOTION, SDL_IGNORE);
	
	do {
		last_time = SDL_GetTicks ();
	
		while (SDL_PollEvent(&event) > 0) {
			switch (event.type) {
				case SDL_QUIT:
					/* Vamos a cerrar la aplicación */
					done = GAME_QUIT;
					break;
			}
		}
		
		SDL_BlitSurface (images[fondo_inicio[mine_array[current_seg]] + fondo_frame], NULL, screen, NULL);
		
		fondo_frame++;
		if (fondo_frame > fondo_topframes[mine_array[current_seg]]) {
			fondo_frame = 0;
			current_seg++;
			printf ("Entrando al segmento %i, Bloque no %i\n", current_seg, mine_array[current_seg]);
			if (mine_array[current_seg] == -1) done = GAME_CONTINUE;
		}
		
		SDL_UpdateWindowSurface (window);
		
		now_time = SDL_GetTicks ();
		if (now_time < last_time + FPS) SDL_Delay (last_time + FPS - now_time);
		
	} while (!done);
	
	return done;
}

void setup (void) {
	SDL_Surface * image;
	int g;
	
	/* Inicializar el Video SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf (stderr,
		"Error: Can't initialize the video subsystem\n"
		"The error returned by SDL2 is:\n"
		"%s\n", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	
	/* Crear la pantalla de dibujado */
	window = SDL_CreateWindow ("Cart Surfer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 760, 480, 0);
	
	if (window == NULL) {
		fprintf (stderr,
		"Error: Can't create 760x480 window.\n"
		"The error returned by SDL2 is:\n"
		"%s\n", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	
	screen = SDL_GetWindowSurface (window);
	
	if (screen == NULL) {
		fprintf (stderr,
		"Error: Can't recover surface from window.\n"
		"The error returned by SDL2 is:\n"
		"%s\n", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	
	for (g = 0; g < NUM_IMAGES; g++) {
		image = IMG_Load (images_names[g]);
		
		if (image == NULL) {
			fprintf (stderr,
			"Failed to load data file:\n"
			"%s\n"
			"The error returned by SDL is:\n"
			"%s\n", images_names[g], SDL_GetError());
			SDL_Quit ();
			exit (1);
		}
		
		images[g] = image;
		/* TODO: Mostrar la carga de porcentaje */
	}
	
	srand (SDL_GetTicks ());
}

