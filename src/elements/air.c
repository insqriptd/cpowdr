#include "air.h"

void AIR_UPDATE (struct Particle* particle) {};
struct Particle AIR () {
	struct Particle particle;

	particle.v = 0;
	particle.r = 0;
	particle.g = 0;
	particle.b = 0;

	particle.update = &AIR_UPDATE;
	return particle;
}
