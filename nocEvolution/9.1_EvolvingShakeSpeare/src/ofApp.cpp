#include "ofApp.h"

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))


string target = "to be or not to be";
float mutationRate = 0.01f;

int generation = 0;

ofTrueTypeFont myFont;

bool foundSolution = false;
class DNA
{
public:
    char genes[18]; 
    float fitness;
    
    DNA()
    {
        for (int i = 0; i < ArrayCount(genes); i++)
        {
            genes[i] = (char)ofRandom(32, 128);
        }
    }

    void Fitness()
    {
        int score = 0;
        for (int i = 0; i < ArrayCount(genes); i++)
        {
            if (genes[i] == target[i])
            {
                score++;
            }
        }

		fitness = (float)score / ArrayCount(genes);
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
			if (ofRandom(0, 1) < mutationRate)
			{
				genes[i] = (char)ofRandom(32, 128);
			}
		}
	}
};

DNA population[100];
//--------------------------------------------------------------
void ofApp::setup()
{
    for (int i = 0; i < ArrayCount(population); i++)
    {
        population[i] = DNA();
    }
	myFont.loadFont("LiberationMono-Regular.ttf", 12);
}

const int POPULATION_PER_COLUMN = 25;
const int COLUMN_COUNT = 4;
const int Y_SPACING = 280;
const int X_SPACING = 20;
const int BUFFER_SPACING = 20;
//--------------------------------------------------------------
void ofApp::draw()
{
	if (!foundSolution)
	{
		for (int i = 0; i < ArrayCount(population); i++)
		{
			population[i].Fitness();
		}

		vector<DNA> matingPool = vector<DNA>();
		for (int i = 0; i < ArrayCount(population); i++)
		{
			int n = int(population[i].fitness * ArrayCount(population));
			for (int k = 0; k < n; k++)
			{
				matingPool.push_back(population[i]);
			}
		}

		for (int i = 0; i < ArrayCount(population); i++)
		{
			int a = int(ofRandom(0, matingPool.size()));
			int b = int(ofRandom(0, matingPool.size()));

			DNA parentA = matingPool[a];
			DNA parentB = matingPool[b];

			DNA child = parentA.crossover(parentB);
			child.mutate();

			population[i] = child;
		}
	}

	ofClear(ofColor::white);

	ofSetColor(ofColor::black);
	for (int i = 0; i < ArrayCount(population); i++)
	{
		//string str = population[i].genes;
		population[i].genes[ArrayCount(population[i].genes)] = '\0';

		if (population[i].genes == target)
		{
			foundSolution = true;
			ofNoFill();
			ofSetLineWidth(6);
			ofSetCurveResolution(200);
			ofCircle(ofPoint((int(i / POPULATION_PER_COLUMN) * Y_SPACING) + 100, 
								((i % POPULATION_PER_COLUMN) * X_SPACING) + BUFFER_SPACING), 120);
		}
		

		myFont.drawString(population[i].genes, 
							(int(i / POPULATION_PER_COLUMN) * Y_SPACING) + BUFFER_SPACING, 
							((i % POPULATION_PER_COLUMN) * X_SPACING) + BUFFER_SPACING);

	}

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
