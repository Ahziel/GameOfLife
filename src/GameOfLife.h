#pragma once

#include "ofMain.h"

class GameOfLife
{

public :

	GameOfLife();
	GameOfLife(const int windowSize, const int gridSize = 80);

	void draw();

	void createBlankGrid();
	void createRandomGrid();
	void applyRules();

	bool getValue(const int i, const int j) const;
	void setValue(const int i, const int j, const bool value);

	int m_gridSize;
	float m_squareSize;
	std::vector<bool> m_grid;
};

