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
	/* TODO: Listar las imágenes */
	//IMG_DUMMY,

	NUM_IMAGES
};

const char *images_names[NUM_IMAGES] = {
	/* TODO: Listar las rutas */
	GAMEDATA_DIR "images/dummy.png",
};

/* TODO: Listar aquí los automátas */

/* Codigos de salida */
enum {
	GAME_NONE = 0, /* No usado */
	GAME_CONTINUE,
	GAME_QUIT
};

/* Estructuras */

/* Prototipos de función */
int game_loop (void);
void setup (void);

/* Variables globales */
SDL_Window * window;
SDL_Surface *screen;
SDL_Surface * images [NUM_IMAGES];

int main (int argc, char *argv[]) {

	setup ();

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

