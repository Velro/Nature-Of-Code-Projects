#pragma once

#include "Particle.h"

class Confetti :
	public Particle
{
public:
	Confetti();
	Confetti(Vector2 l, ofImage* _image);

	virtual void Draw();

	ofColor color;
	float theta;
};