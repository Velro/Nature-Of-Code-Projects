#include "ofApp.h"

LSystem lsys;
Turtle turtle;

//--------------------------------------------------------------
void ofApp::setup()
{
	Rule ruleset[1];
	ruleset[0] = Rule('F', "FF+[+F-F-F]-[-F+F+F]");

	lsys = LSystem("F", ruleset, 1);

	turtle = Turtle(lsys.getSentence(), 60, 25);
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(ofColor::white);
	ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight());
	ofSetColor(ofColor::black);
	turtle.render();
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
	lsys.generate();
	turtle.setToDo(lsys.getSentence());
	turtle.changeLength(0.3f);
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