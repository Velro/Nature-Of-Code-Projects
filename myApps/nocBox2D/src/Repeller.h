#pragma once

#include "ofMain.h"
#include "Defines.h"
#include "Particle.h"

class Repeller
{
public:
	Repeller();
	Repeller(Vector2 _position);

	~Repeller();

	void Update();
	Vector2 Repel(Particle p);

	Vector2 position;
	float strength;
	float radius;
};