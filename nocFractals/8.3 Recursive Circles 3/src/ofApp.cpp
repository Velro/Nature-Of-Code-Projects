#include "ofApp.h"

void drawCircle(int x, int y, float radius)
{
	ofCircle(x, y, radius);
	if (radius > 8)
	{
		drawCircle(x + radius / 2, y, radius / 2);
		drawCircle(x - radius / 2, y, radius / 2);

		drawCircle(x, y + radius / 2, radius / 2);
		drawCircle(x, y - radius / 2, radius / 2);
	}
}
//--------------------------------------------------------------
void ofApp::setup()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofNoFill();
	ofSetColor(ofColor::blue);
	ofSetCircleResolution(100);
	drawCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 300);
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