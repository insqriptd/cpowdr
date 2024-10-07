#include <stdlib.h>
#include "stone.h"

void STONE_UPDATE (struct Particle* particle) {};
struct Particle STONE () {
	struct Particle particle;
	particle.v = 255;

	int brightness = rand() % 86 + 40;
	particle.r = brightness;
	particle.g = brightness;
	particle.b = brightness;

	particle.update = &STONE_UPDATE;
	return particle;
}
