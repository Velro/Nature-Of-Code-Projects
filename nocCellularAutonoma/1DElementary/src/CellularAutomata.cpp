#include "CellularAutomata.h"


CellularAutomata::CellularAutomata()
{
	ruleset[0] = 0;
	ruleset[1] = 1;
	ruleset[2] = 0;
	ruleset[3] = 1;
	ruleset[4] = 1;
	ruleset[5] = 0;
	ruleset[6] = 1;
	ruleset[7] = 0;


	for (int i = 0; i < cellsCount; i++)
	{
		cells[i] = 0;
	}
	cells[cellsCount / 2] = 1;
}

void CellularAutomata::Generate()
{
	int nextgen[cellsCount];
	for (int i = 0; i < cellsCount; i++)
		nextgen[i] = 0;

	for (int i = 1; i < cellsCount - 1; i++) {
		int left = cells[i - 1];
		int me = cells[i];
		int right = cells[i + 1];

		if (left < 0)
			int k = 0;
		nextgen[i] = Rules(left, me, right);
	}
	
	for (int i = 0; i < cellsCount; i++)
	{
		cells[i] = nextgen[i];
	}

	generation++;
}

int CellularAutomata::Rules(int a, int b, int c) {	
	string s = "" + ofToString(a) + ofToString(b) + ofToString(c);
	int index = 0;
	index = ofBinaryToInt(s);
	int toReturn = 0;
	toReturn = ruleset[index];
	if (toReturn < 0)
		int k = 0;
	return toReturn;
}

void CellularAutomata::Draw()
{
	for (int i = 0; i < cellsCount; i++) {
		if (cells[i] == 1) ofSetColor(0);
		else ofSetColor(255);

		ofRect(i*w, generation*w, w, w);
	}
}
