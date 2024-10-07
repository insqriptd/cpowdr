#include "elements.h"

#include "particle.h"
#include "scene.h"
#include "sim.h"

int determineSideMove (Scene *scene, struct Particle particle) {
	return (scene->ticks + particle.spawnTick) % 2 ? 1 : -1;
}

void simulateScene (Scene *scene) {
	for (int y = 0; y < SCENE_HEIGHT; y++) {
		for (int x = 0; x < SCENE_WIDTH; x++) {
			scene->particles[x][y].simulated = false;
		}
	}

	for (int y = 0; y < SCENE_HEIGHT; y++) {
		for (int x = 0; x < SCENE_WIDTH; x++) {
			struct Particle particle = scene->particles[x][y];

			particle.lifetime = scene->ticks - particle.spawnTick;
			particle.update(&particle);
			if (particle.v > 0 && !particle.simulated) {
				if (!particle.solid) {
					if (isWithinSceneBounds(scene, x, y)) {
						int newX, newY;
						newX = x+determineSideMove(scene, particle);
						newY = y+1;
						particle.simulated = true;

						if (!scene->particles[newX][newY].v) {
							scene->particles[x][y] = AIR();
							scene->particles[newX][newY] = particle;
						}
						else {
							if (!scene->particles[x][newY].v) {
								scene->particles[x][y] = AIR();
								scene->particles[x][newY] = particle;
							}
							else {
								scene->particles[x][y] = particle;
							}
						}
					}
					else {
						destroyParticle(scene, x, y);
					}
				}
			}
			else {
				if (particle.v < 1)
					destroyParticle(scene, x, y);
			}
		}
	}

	scene->ticks++;
}

int instantiateParticle (Scene* scene, int element, int x, int y) {
	if (scene->particles[x][y].v == 0) {
		scene->particles[x][y] = ELEMENTS[element]();
		scene->particles[x][y].lifetime = 0;
		scene->particles[x][y].spawnTick = scene->ticks;

		return 0;
	}

	return -1;
}

int destroyParticle (Scene* scene, int x, int y) {
	if (scene->particles[x][y].v > 0) {
		scene->particles[x][y].v = 0;
		return 0;
	}

	return -1;
}
