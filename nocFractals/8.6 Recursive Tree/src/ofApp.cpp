#include "ofApp.h"


void branch(float length, float theta)
{
	ofLine(0, 0, 0, -length);
	ofTranslate(0, -length);
	length *= 0.66f;
	if (length > 2)
	{
		ofPushMatrix();
		ofRotate(theta);
		branch(length, theta);
		ofPopMatrix();

		ofPushMatrix();
		ofRotate(-theta);
		branch(length, theta);
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void ofApp::setup()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(ofColor::brown);
	ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight());
	branch(80, 20);
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