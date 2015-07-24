#include "ofApp.h"


class KochLine
{
public:
	Vector2 start;
	Vector2 end;

	KochLine(Vector2 a, Vector2 b)
	{
		start = a;
		end = b;
	}

	void display()
	{
		ofLine(start.x, start.y, end.x, end.y);
	}

	Vector2 kochA()
	{
		return start;
	}

	Vector2 kochB()
	{
		Vector2 v = end - start;
		v *= 0.33f;
		v += start;
		return v;
	}

	Vector2 kochC()
	{
		Vector2 result = start;
		Vector2 v = end - start;
		v /= 3;
		result += v;
		v.rotate(-60);
		result += v;
		return result;
	}

	Vector2 kochD()
	{
		Vector2 v = end - start;
		v *= 0.66f;
		v += start;
		return v;
	}

	Vector2 kochE()
	{
		return end;
	}
};

vector<KochLine> lines;

void generate()
{
	vector<KochLine> next;
	for (int i = 0; i < lines.size(); i++)
	{
		Vector2 a = lines[i].kochA();
		Vector2 b = lines[i].kochB();
		Vector2 c = lines[i].kochC();
		Vector2 d = lines[i].kochD();
		Vector2 e = lines[i].kochE();

		next.push_back(KochLine(a, b));
		next.push_back(KochLine(b, c));
		next.push_back(KochLine(c, d));
		next.push_back(KochLine(d, e));
	}
	lines = next;
}

//--------------------------------------------------------------
void ofApp::setup()
{
	Vector2 start = Vector2(0, 400);
	Vector2 end = Vector2(ofGetWindowWidth(), 400);

	lines.push_back(KochLine(start, end));

	for (int i = 0; i < 5; i++)
	{
		generate();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(ofColor::blue);
	for (int i = 0; i < lines.size(); i++)
	{
		lines[i].display();
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