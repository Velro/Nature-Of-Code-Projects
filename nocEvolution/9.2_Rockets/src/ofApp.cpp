#include "ofApp.h"

Vector2 random2D()
{
	Vector2 result;

	float angle = ofRandom(0, 360);
	result.x = 1 * cos(angle);
	result.y = 1 * sin(angle);

	return result;
}


class DNA
{
public:

	Vector2 genes[LIFETIME];
	float maxforce = 0.1f;

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

class Rocket
{
public:
	Vector2 position = Vector2(0, 0);
	Vector2 velocity = Vector2(0, 0);
	Vector2 acceleration = Vector2(0, 0);

	float fitness = 0;

	DNA dna;

	Rocket()
	{
		
	}

	Rocket(Vector2 pos)
	{
		position = pos;
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
		applyForce(dna.genes[geneCounter]);
		geneCounter++;

		update();
		draw();
	}

	void calcFitness()
	{
		//NOTE: this isn't a good way of calculating fitness,
		// this will be explored more in later examples
		float d = position.distance(targetPos);
		if (d > 800)
			d = 800;
		fitness = ofLerp(1, 0, d / 700);
	}	
};


class Population
{
public:
	Rocket population[POPULATION_COUNT];
	vector<Rocket> matingPool;
	int generation;

	Vector2 startingPosition;
	Population()
	{

	}

	Population(Vector2 pos)
	{
		startingPosition = pos;
		for (int i = 0; i < POPULATION_COUNT; i++)
		{
			
			Rocket rocket = Rocket(pos);
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

			population[i] = Rocket(startingPosition);
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

int lifeCounter = 0;

Population population;
//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);

	targetPos = Vector2(ofGetWindowWidth() / 2, ofGetWindowHeight() / 6);
	Vector2 pos = Vector2(ofGetWindowWidth() / 2, ofGetWindowHeight());
	population = Population(pos);
}


//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(ofColor::white);

	ofSetColor(ofColor::black);
	ofNoFill();
	ofSetLineWidth(5);
	ofRect(ofPoint(targetPos) - ofPoint(10,10), 20, 20);
	
	
	if (lifeCounter < LIFETIME)
	{
		population.live();
		lifeCounter++;
	}
	else
	{
		lifeCounter = 0;
		population.fitness();
		population.selection();
		population.reproduction();
		population.generation++;
	}
	
}
