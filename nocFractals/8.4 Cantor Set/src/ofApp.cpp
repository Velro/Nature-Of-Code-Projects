#include "ofApp.h"

void cantor(float x, float y, float length)
{
	if (length >= 1)
	{
		ofLine(x, y, 0, x + length, y, 0);

		y += 20;

		cantor(x, y, length / 3);
		cantor(x + length * 2 / 3, y, length / 3);
	}

}

//--------------------------------------------------------------
void ofApp::setup()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(ofColor::blue);
	cantor(0, 20, ofGetWindowWidth());
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