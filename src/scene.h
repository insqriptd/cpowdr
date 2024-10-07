#ifndef SCENE_H
#define SCENE_H

#include "particle.h"

#define SCENE_WIDTH		256
#define SCENE_HEIGHT	128
#define SCENE_PARTICLES SCENE_WIDTH * SCENE_HEIGHT

typedef struct {
	struct Particle particles[SCENE_WIDTH][SCENE_HEIGHT];
	int ticks;
} Scene;

Scene* sceneInit ();
bool isWithinSceneBounds (Scene* scene, int x, int y); // Checks if provided position fits within the bounds of the scene.

#endif
