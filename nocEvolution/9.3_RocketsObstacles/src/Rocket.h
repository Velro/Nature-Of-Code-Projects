#pragma once

#include "Defines.h"
#include "DNA.h"

class Rocket
{
public:
	Vector2 position = Vector2(0, 0);
	Vector2 velocity = Vector2(0, 0);
	Vector2 acceleration = Vector2(0, 0);

	float fitness = 0;
	bool stopped = false;
	DNA dna;

	vector<ofRectangle> * obstacles;
	Vector2 targetPosition;

	Rocket()
	{

	}

	Rocket(Vector2 _position, Vector2 _targetPosition, vector<ofRectangle> * _obstacles)
	{
		position = _position;
		obstacles = _obstacles;
		targetPosition = _targetPosition;
	}
	void applyForce(Vector2 force)
	{
		acceleration += force;
	}

	void update()
	{
		velocity += acceleration;
		position += velocity;
		acceleration *= 0;
	}

	void draw()
	{
		ofDrawArrow(position, position + velocity, 0.1f);
	}

	int geneCounter = 0;
	void run()
	{
		if (!stopped)
		{
			applyForce(dna.genes[geneCounter]);
			geneCounter++;

			update();
			checkObstacles();
			draw();
		}

	}

	void calcFitness()
	{
		//NOTE: this isn't a good way of calculating fitness,
		// this will be explored more in later examples
		float d = position.distance(targetPosition);
		if (d > 700)
			d = 700;
		fitness = ofLerp(1, 0, d / 700);
		if (stopped) 
			fitness *= 0.1f;
	}

	void checkObstacles()
	{
		for (int i = 0; i < obstacles->size(); i++)
		{
			ofRectangle rect = obstacles->at(i);
			if (rect.inside(position))
			{
				stopped = true;
			}
		}
	}
};