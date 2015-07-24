#pragma once

#include "ofMain.h"
#include "Rule.h"

class LSystem
{
public:
	string sentence;
	Rule* ruleset;
	int rulesetCount;

	LSystem()
	{

	}

	LSystem(string axiom, Rule* _ruleset, int rulesetCounts)
	{
		sentence = _ruleset[0].rule;
		ruleset = _ruleset;
	}

	string getSentence()
	{
		return sentence;
	}

	void generate()
	{
		//string sentence = ruleset[0].rule;
		string building;
		for (int i = 0; i < sentence.size(); i++)
		{
			char c = sentence[i];
			switch (c)
			{
				case 'F':
					building += sentence;
				break;

				default:
					building += c;
				
			}
		}

		sentence = building;
	}
};