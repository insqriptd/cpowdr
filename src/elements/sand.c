#include <stdlib.h>
#include "sand.h"

void SAND_UPDATE (struct Particle* particle) {};
struct Particle SAND () {
	struct Particle particle;

	particle.v = 255;
	particle.r = 255;
	particle.g = 230;
	particle.b = rand() % 105 + 1;

	particle.update = &SAND_UPDATE;
	return particle;
}
