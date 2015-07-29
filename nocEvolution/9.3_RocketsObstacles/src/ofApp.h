#pragma once
#pragma once

#include "ofMain.h"
#include "Defines.h"
#include "Population.h"
#include "Rocket.h"
#include "DNA.h"



class ofApp : public ofBaseApp
{
public:

	void setup();
	void draw();
		
	vector<ofRectangle> obstacles;
	int lifeCounter = 0;
	Vector2 targetPosition;

	Population population;
};
