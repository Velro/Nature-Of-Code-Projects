#pragma once

#include "Defines.h"
#include "ofMain.h"

#define LIFETIME 100
#define MUTATION_RATE 0.01f

class DNA
{
public:

	Vector2 genes[LIFETIME];
	float maxforce = 0.1f;

	Vector2 random2D()
	{
		Vector2 result;

		float angle = ofRandom(0, 360);
		result.x = 1 * cos(angle);
		result.y = 1 * sin(angle);

		return result;
	}

	DNA()
	{
		//genes = Vector2[lifetime];
		for (int i = 0; i < ArrayCount(genes); i++)
		{
			genes[i] = random2D();
			genes[i] *= ofRandom(0, maxforce);
		}
	}

	DNA crossover(DNA partner)
	{
		DNA child = DNA();

		int midpoint = int(ofRandom(0, ArrayCount(genes)));

		for (int i = 0; i < ArrayCount(genes); i++)
		{
			if (i > midpoint)child.genes[i] = genes[i];
			else child.genes[i] = partner.genes[i];
		}

		return child;
	}

	void mutate()
	{
		for (int i = 0; i < ArrayCount(genes); i++)
		{
			if (ofRandom(0, 1) < MUTATION_RATE)
			{
				genes[i] = random2D();
			}
		}
	}
};