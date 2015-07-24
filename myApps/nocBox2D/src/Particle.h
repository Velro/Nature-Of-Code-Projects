#pragma once

#include "ofMain.h"
#include "Defines.h"

class Particle
{
public:
	Particle();
	Particle(Vector2 l, ofImage* _image);
	~Particle();

	void Start();
	void Update();
	virtual void Draw();
	void ApplyForce(Vector2 force);

	bool isDead();

	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;

	float mass;
	float lifespan;

	ofImage* image;
};

