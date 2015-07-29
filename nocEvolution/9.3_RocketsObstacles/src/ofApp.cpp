#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);

	targetPosition = Vector2(ofGetWindowWidth() / 2, ofGetWindowHeight() / 6);
	obstacles = vector<ofRectangle>();
	obstacles.push_back(ofRectangle(ofPoint(ofGetWindowWidth() / 3, ofGetWindowHeight() / 2), 250, 20));
	obstacles.push_back(ofRectangle(ofPoint(100, ofGetWindowHeight() / 3), 200, 20));
	obstacles.push_back(ofRectangle(ofPoint(ofGetWindowWidth() / 3, (ofGetWindowHeight() / 4) * 3), 250, 20));
	Vector2 pos = Vector2(ofGetWindowWidth() / 2, ofGetWindowHeight());
	population = Population(pos, targetPosition, &obstacles);
}


//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(ofColor::white);

	ofSetColor(ofColor::black);
	ofNoFill();
	ofSetLineWidth(5);
	ofRect(ofPoint(targetPosition) - ofPoint(10, 10), 20, 20);
	
	for (int i = 0; i < obstacles.size(); i++)
	{
		ofRect(obstacles[i]);
	}
	
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
