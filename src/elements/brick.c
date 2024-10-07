#include "brick.h"

void BRICK_UPDATE (struct Particle* particle) {};
struct Particle BRICK () {
	struct Particle particle;

	particle.v = 255;
	particle.r = 230;
	particle.g = 26;
	particle.b = 26;
	particle.solid = true;

	particle.update = &BRICK_UPDATE;
	return particle;
}
