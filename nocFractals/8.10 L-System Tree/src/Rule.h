#pragma once

#include "ofMain.h"
class Rule
{
public:
	Rule()
	{

	}

	char axiom;
	string rule;

	Rule(char c, string turtleRules )
	{
		axiom = c;
		rule = turtleRules;
	}


};