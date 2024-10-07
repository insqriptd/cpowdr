#ifndef SIM_H
#define SIM_H

#include <stdint.h>
#include "scene.h"

#define DESTROY_AT_BOUNDARIES false

void simulateScene (Scene* scene);

int instantiateParticle (Scene* scene, int element, int x, int y);
int destroyParticle (Scene* scene, int x, int y);

#endif
