#include "ofApp.h"

string current = "A";
int genCount = 0;
//--------------------------------------------------------------
void ofApp::setup()
{
	ofLog(OF_LOG_NOTICE, "Generation " + ofToString(genCount) + ": " + current);
}

//--------------------------------------------------------------
void ofApp::draw()
{

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
void ofApp::mousePressed(int x, int y, int button)
{
	string next = "";
#if 1
	for (int i = 0; i < current.length(); i++)
	{
		char c = current[i];
		if (c == 'A')
		{
			next += "AB";
		}
		else if (c == 'B')
		{
			next += "A";
		}
	}
#endif
	current = next;
	genCount++;
	ofLog(OF_LOG_NOTICE, "Generation " + ofToString(genCount) + ": " + current);
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