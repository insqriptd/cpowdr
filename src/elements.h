#include "elements/air.h"
#include "elements/sand.h"
#include "elements/stone.h"
#include "elements/brick.h"

static struct Particle (*ELEMENTS[])() = {
	SAND,
	STONE,
	BRICK
};
#define NUM_ELEMENTS 3
