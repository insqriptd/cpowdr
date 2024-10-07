#ifndef PARTICLE_H
#define PARTICLE_H

#include <stdbool.h>
#include <stdint.h>

struct Particle {
	int v;
	int spawnTick; // Number of the frame the particle was changed at
	int lifetime;

	int r;
	int g;
	int b;
	bool solid;

	void (*update)(struct Particle* particle);

	bool simulated; // When simulated, this is set to true until next frame. Used for preventing repeated simulation as we're  simulating on a 2D array.
};

#endif
