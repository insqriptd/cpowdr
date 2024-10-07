#include <SDL2/SDL_render.h>

#include "brush.h"
#include "clamp.h"
#include "elements.h"
#include "sim.h"

Brush* brushInit (Scene* scene) {
	Brush* brush = calloc(5, sizeof(Brush));
	brush->scene = scene;

	return brush;
}

void brushMove (Brush* brush, SDL_MouseMotionEvent event) {
	brush->x = event.x;
	brush->y = event.y;
}

void brushSetMode (Brush* brush, int mode) {
	brush->mode = mode;
}

void brushChangeElement (Brush* brush, int scrollDir) {
	brush->element = clampInt(brush->element + scrollDir, 0, NUM_ELEMENTS-1);
}

void brushUpdate (Brush* brush) {
	if (isWithinSceneBounds(brush->scene, brush->x, brush->y)) {
		if (brush->mode == BRUSH_DRAW) {
			instantiateParticle(brush->scene, brush->element, brush->x, brush->y);
		}
		else {
			if (brush->mode == BRUSH_ERASE) {
				destroyParticle(brush->scene, brush->x, brush->y);
			}
		}
	}
}

void brushRender (Brush* brush, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, BRUSH_COLOR);
	SDL_RenderDrawPoint(renderer, brush->x, brush->y);
}
