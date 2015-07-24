#include "CellularAutomata.h"


CellularAutomata::CellularAutomata()
{
	//init board to zero
	for (int i = 0; i < cellsCount; i++)
	{
		for (int k = 0; k < cellsCount; k++)
		{
			board[i][k] = (int)ofRandom(0,2);

		}
	}
	/*
	//blinker
	board[79][80] = 1;
	board[80][80] = 1;
	board[81][80] = 1;

	//spaceship
	board[1][1] = 1;
	board[1][4] = 1;
	board[2][5] = 1;
	board[3][1] = 1;
	board[3][5] = 1;
	board[4][2] = 1;
	board[4][3] = 1;
	board[4][4] = 1;
	board[4][5] = 1;
	*/
}

void CellularAutomata::Generate()
{
	//init fresh board
	int next[cellsCount][cellsCount];
	for (int i = 0; i < cellsCount; i++)
	{
		for (int k = 0; k < cellsCount; k++)
		{
			next[i][k] = 0;
		}
	}

	//fill fresh board
	for (int x = 1; x < cellsCount - 1; x++) {
		for (int y = 1; y < cellsCount - 1; y++) {
				int neighbors = 0;
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					neighbors += board[x + i][y + j];
				}
			}
			neighbors -= board[x][y];
				if ((board[x][y] == 1) && (neighbors < 2)) next[x][y] = 0;
				else if ((board[x][y] == 1) && (neighbors > 3)) next[x][y] = 0;
				else if ((board[x][y] == 0) && (neighbors == 3)) next[x][y] = 1;
				else next[x][y] = board[x][y];
			}
	}

	//set board to fresh board
	for (int i = 0; i < cellsCount; i++)
	{
		for (int k = 0; k < cellsCount; k++)
		{
			board[i][k] = next[i][k];
		}
	}

	generation++;
}

void CellularAutomata::Draw()
{
	for (int i = 0; i < cellsCount; i++) 
	{
		for (int j = 0; j < cellsCount; j++) 
		{
			if ((board[i][j] == 1))
			{
				ofSetColor(0);
			}
			else
			{
				ofSetColor(255);
			}
			ofRect(i*w, j*w, w, w);
		}
	}
}
