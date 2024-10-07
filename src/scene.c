#include <SDL2/SDL_stdinc.h>
#include <stdlib.h>

#include "elements/air.h"
#include "scene.h"

Scene* sceneInit () {
	Scene* scene = calloc(2, sizeof(Scene));

	// Fill scene with AIR
	for (int y = 0; y < SCENE_HEIGHT; y++) {
		for (int x = 0; x < SCENE_WIDTH; x++)
			scene->particles[x][y] = AIR();
	}

	return scene;
}

bool isWithinSceneBounds (Scene* scene, int x, int y) {
	return (x > 0 && x < SCENE_WIDTH-1 && y > 0 && y < SCENE_HEIGHT-2);
}
