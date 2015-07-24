#pragma once
#include "Defines.h"
#include "ofMain.h"


class CellularAutomata
{
public:
	CellularAutomata();
	void Generate();
	void Draw();

	static const int cellsCount = 160;
	int board[cellsCount][cellsCount];

	int w = 5;
	int generation = 0;

};

