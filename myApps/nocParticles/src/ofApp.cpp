#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);
	screenCenter.x = ofGetWindowWidth() / 2;
	screenCenter.y = ofGetWindowHeight() / 4;
	
	particleSystem = ParticleSystem(screenCenter);
	particleSystem.Setup();
	repeller = Repeller(screenCenter + Vector2(0, ofGetWindowHeight() / 4));
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0, 0);

	
	Vector2 gravity = Vector2(0, 0.1f);
	particleSystem.ApplyForce(gravity);
	particleSystem.Update();
	particleSystem.ApplyRepeller(repeller);

	repeller.Update();
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