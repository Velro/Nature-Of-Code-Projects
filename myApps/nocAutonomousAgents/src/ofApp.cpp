#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);
	v = Vehicle(Vector2(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2));
}

float x = 400;
float y = 0;
//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(255, 255, 255);
	y+=2;
	if (y > 800) y = 0;//wrap
	ofDrawSphere(ofPoint(x, y), 10);
	v.Seek(Vector2(x, y));
	v.Update();
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