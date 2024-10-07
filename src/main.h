#include <SDL2/SDL_render.h>
#include "scene.h"

#define SDL_INIT_FLAGS	SDL_INIT_VIDEO

#define WINDOW_TITLE	"C Powder"
#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480
#define WINDOW_FLAGS	SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE

#define RENDERER_FLAGS	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

int main ();
void renderScene (Scene* scene, SDL_Renderer* renderer);
SDL_Renderer* renderInit (Scene* scene, SDL_Window* window);
