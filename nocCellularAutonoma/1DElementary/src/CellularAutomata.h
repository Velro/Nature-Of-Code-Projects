#pragma once
#include "Defines.h"
#include "ofMain.h"


class CellularAutomata
{
public:
	CellularAutomata();
	void Generate();
	int Rules(int a, int b, int c);
	void Draw();

	int cells[160];
	static const int cellsCount = 160;
	int ruleset[8];

	int w = 5;
	int generation = 0;

};

