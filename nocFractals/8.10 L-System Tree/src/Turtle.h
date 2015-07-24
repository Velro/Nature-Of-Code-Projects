#pragma once

#include "ofMain.h"

class Turtle
{
public:
	string sentence;
	float startingLength;
	float rotationAngle;

	Turtle()
	{

	}

	Turtle(string _sentence, float _startingLength, float _rotationAngle)
	{
		sentence = _sentence;
		startingLength = _startingLength;
		rotationAngle = _rotationAngle;
	}

	void render()
	{
		for (int i = 0; i < sentence.size(); i++)
		{
			char c = sentence[i];
			switch (c)
			{
				case 'F':
					ofLine(ofPoint(0, 0), ofPoint(0, -startingLength));
					ofTranslate(0, -startingLength);
				break;

				case 'G':
					ofTranslate(0, -startingLength);
				break;

				case '+':
					ofRotate(rotationAngle);
				break;

				case '-':
					ofRotate(-rotationAngle);
				break;

				case '[':
					ofPushMatrix();
				break;

				case ']':
					ofPopMatrix();
				break;
			}
		}
	}

	void setToDo(string _sentence)
	{
		sentence = _sentence;
	}

	void changeLength(float lengthChangeMultiplier)
	{
		startingLength *= lengthChangeMultiplier;
	}
};