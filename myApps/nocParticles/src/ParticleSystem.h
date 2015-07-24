#pragma once

#include "ofMain.h"
#include "Defines.h"
#include "Particle.h"
#include "Confetti.h"
#include "Repeller.h"

const int particleCount = 20;



class ParticleSystem
{
public:
	ParticleSystem();
	ParticleSystem(Vector2 _startPos);

	void Setup();

	void Update();
	void ApplyForce(Vector2 force);
	void ApplyRepeller(Repeller repeller);

	Vector2 startPos;
	vector<Particle*> particleList;

	ofImage particleImage;
	ofImage* imagePointer;

	int i;
	int* pointer;
};

