#include "Confetti.h"

Confetti::Confetti()
{

}

Confetti::Confetti(Vector2 l, ofImage* _image) :Particle(l, _image)
{
	color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 255);
}

void Confetti::Draw()
{
	Update();
	
	
	theta += 10.0f;
	theta = ofWrapDegrees(theta);
	//theta = ofMap(theta, location.x, 0, ofGetWindowWidth(), TWO_PI * 2);
	
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofPushMatrix();
		ofTranslate(position.x, position.y);
		ofRotateZ(theta);
		ofRect(0, 0, 20, 20);
		ofSetColor(color.r, color.g, color.b, lifespan);
//		ofDrawBox(Vector2(0,0), 20.0f);
	ofPopMatrix();
}