#include "ofApp.h"

#define MUTATION_RATE 0.1f
Vector2 random2D()
{
	Vector2 result;

	float angle = ofRandom(0, PI);
	result.x = 1 * cos(angle);
	result.y = 1 * sin(angle);

	return result;
}

Vector2 targetPos;

#define LIFETIME 120
class DNA
{
public:

	Vector2 genes[LIFETIME];// = Vector2[100];
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
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;

	float fitness;

	DNA dna;

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

	int geneCounter = 0;
	void run()
	{
		applyForce(dna.genes[geneCounter]);
		geneCounter++;

		update();
	}

	void calcFitness()
	{
		float d = position.distance(targetPos);
		fitness = (1 / d)*(1 / d);
	}	
};

#define POPULATION_COUNT 100
class Population
{
public:
	Rocket population[POPULATION_COUNT];
	vector<Rocket> matingPool;
	int generation;

	Population()
	{
	
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

			population[i].dna = child;
		}
	}
};

int lifetime;
int lifeCounter;

Population population;

//--------------------------------------------------------------
void ofApp::setup()
{
	targetPos = Vector2(ofGetWindowWidth() / 2, ofGetWindowHeight() / 4);
	population = Population();
}


//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(ofColor::white);

	ofSetColor(ofColor::black);
	ofNoFill();
	ofSetLineWidth(5);
	ofRect(ofPoint(targetPos), 50, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}