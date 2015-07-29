#pragma once
#pragma once

#include "ofMain.h"
#include "Defines.h"


#define POPULATION_COUNT 200
#define MUTATION_RATE 0.01f
#define LIFETIME 100

static Vector2 targetPos;
class ofApp : public ofBaseApp
{
	public:

		void setup();
		void draw();

};
