#pragma once

#include "Rocket.h"
#include "DNA.h"
#include "Defines.h"

#define POPULATION_COUNT 200

class Population
{
public:
	Rocket population[POPULATION_COUNT];
	vector<Rocket> matingPool;
	int generation;

	Vector2 startingPosition;
	vector<ofRectangle> * obstacles;
	Vector2 targetPosition;

	Population()
	{

	}

	Population(Vector2 pos, Vector2 _targetPosition, vector<ofRectangle> * _obstacles)
	{
		startingPosition = pos;
		for (int i = 0; i < POPULATION_COUNT; i++)
		{

			Rocket rocket = Rocket(pos, _targetPosition, _obstacles);
			obstacles = _obstacles;
			targetPosition = _targetPosition;
			
			rocket.dna = DNA();
			matingPool.push_back(rocket);
			population[i] = rocket;
			generation = 0;
			
		}
	}

	void fitness()
	{
		for (int i = 0; i < ArrayCount(population); i++)
		{
			population[i].calcFitness();
		}
	}

	void selection()
	{
		matingPool.clear();
		for (int i = 0; i < ArrayCount(population); i++)
		{
			int n = int(population[i].fitness * ArrayCount(population));
			for (int k = 0; k < n; k++)
			{
				matingPool.push_back(population[i]);
			}
		}
	}

	void reproduction()
	{
		for (int i = 0; i < ArrayCount(population); i++)
		{
			int a = int(ofRandom(0, matingPool.size()));
			int b = int(ofRandom(0, matingPool.size()));

			DNA parentA = matingPool[a].dna;
			DNA parentB = matingPool[b].dna;

			DNA child = parentA.crossover(parentB);
			child.mutate();

			population[i] = Rocket(startingPosition, targetPosition, obstacles);
			population[i].dna = child;
		}
	}

	void live()
	{
		for (int i = 0; i < ArrayCount(population); i++)
		{
			population[i].run();
		}
	}
};