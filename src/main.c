#include <SDL2/SDL_events.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include "main.h"

#include "brush.h"
#include "scene.h"
#include "sim.h"

int main () {
	Scene* scene = sceneInit();
	Brush* brush = brushInit(scene);

	if (SDL_Init(SDL_INIT_FLAGS) != 0) {
		fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
		return -1;
	}
	SDL_ShowCursor(SDL_DISABLE);

	SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE,
										  SDL_WINDOWPOS_UNDEFINED,
										  SDL_WINDOWPOS_UNDEFINED,
										  WINDOW_WIDTH,
										  WINDOW_HEIGHT,
										  WINDOW_FLAGS);
	if (!window) {
		printf("Failed to create SDL window: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Renderer* renderer = renderInit(scene, window);
	if (!renderer) {
		printf("Failed to create SDL renderer: %s\n", SDL_GetError());
		return -1;
	}

	bool run = true;
	while (run) {
		srand(clock());

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				run = false;

			// Brush movement
			if (event.type == SDL_MOUSEMOTION) {
					brushMove(brush, event.motion);
					brushUpdate(brush); // Helps prevent skipping
			}

			// Brush control
			if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
				int mode = event.button.button == SDL_BUTTON_LEFT ? BRUSH_DRAW : BRUSH_ERASE;
				brushSetMode(brush, event.button.type == SDL_MOUSEBUTTONDOWN ? mode : BRUSH_NONE);
			}

			if (event.type == SDL_MOUSEWHEEL) {
				brushChangeElement(brush, event.wheel.y);
			}
		}

		brushUpdate(brush);
		simulateScene(scene);

		renderScene(scene, renderer);
		brushRender(brush, renderer);

		SDL_RenderPresent(renderer);
	}
	return 0;
}

SDL_Renderer* renderInit (Scene* scene, SDL_Window* window) {
	SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, RENDERER_FLAGS);
	SDL_RenderSetLogicalSize(renderer, SCENE_WIDTH, SCENE_HEIGHT);

	return renderer;
}

void renderScene (Scene* scene, SDL_Renderer* renderer) {
	for (int y = 0; y < SCENE_HEIGHT; y++) {
		for (int x = 0; x < SCENE_WIDTH; x++) {
			struct Particle particle = scene->particles[x][y];

			if (particle.v > 0) {
				SDL_SetRenderDrawColor(renderer, particle.r, particle.g, particle.b, 255);
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
	}
}
