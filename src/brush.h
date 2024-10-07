#include <stdbool.h>
#include <SDL2/SDL.h>

#include "scene.h"

#define BRUSH_COLOR 255, 255, 255, 127
typedef struct {
	Scene* scene;
	int x, y;

	int mode;
	int element;
} Brush;

enum brushMode {
	BRUSH_NONE,
	BRUSH_ERASE,
	BRUSH_DRAW
};

Brush* brushInit (Scene* scene);

void brushMove (Brush* brush, SDL_MouseMotionEvent event);
void brushSetMode (Brush* brush, int mode);
void brushChangeElement (Brush* brush, int scrollDir);

void brushUpdate (Brush* brush);
void brushRender (Brush* brush, SDL_Renderer* renderer);
