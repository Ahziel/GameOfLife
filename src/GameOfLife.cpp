#include "GameOfLife.h"


GameOfLife::GameOfLife()
{
	m_gridSize = 0;
	m_squareSize = 0;
	m_grid.resize(m_gridSize * m_gridSize, 0);
}

GameOfLife::GameOfLife(const int windowSize, const int gridSize)
{
	m_gridSize = gridSize;
	m_squareSize = (float)windowSize / (float)m_gridSize;

	// Set grid size
	m_grid.resize(m_gridSize * m_gridSize, 0);
}

void GameOfLife::draw()
{
	for (int i = 0; i < m_gridSize; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			ofSetColor(getValue(i,j) * 255);
			ofDrawRectangle(i * m_squareSize + 1.0, j * m_squareSize + 1.0, m_squareSize - 1.0, m_squareSize - 1.0);
		}
	}
}

void GameOfLife::createBlankGrid()
{
	for (int i = 0; i < m_gridSize; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			m_grid[i * m_gridSize + j] = false;
		}
	}
}

void GameOfLife::createRandomGrid()
{
	for (int i = 0; i < m_gridSize; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			bool val = (int)ofRandom(0, 2);
			m_grid[i * m_gridSize + j] = val;
		}
	}
}

void GameOfLife::applyRules()
{

	std::vector<bool> newGrid(m_grid);

	for (int i = 0; i < m_gridSize; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			int livingCells = 0;

			livingCells += getValue(i - 1, j - 1);
			livingCells += getValue(i - 1, j);
			livingCells += getValue(i - 1, j + 1);

			livingCells += getValue(i , j - 1);
			livingCells += getValue(i , j + 1);

			livingCells += getValue(i + 1, j - 1);
			livingCells += getValue(i + 1, j);
			livingCells += getValue(i + 1, j + 1);

			if (!getValue(i, j))
			{
				if (livingCells == 3)
				{
					newGrid[i * m_gridSize + j] = true;
				}
			}
			else
			{
				if (!(livingCells == 2 || livingCells == 3))
				{
					newGrid[i * m_gridSize + j] = false;
				}
			}

		}
	}

	m_grid = newGrid;
}

bool GameOfLife::getValue(int i, int j) const
{
	if (i < 0 || i >= m_gridSize || j < 0 || j >= m_gridSize)
	{
		return false;
	}
	else
	{
		return m_grid[i * m_gridSize + j];
	}
}

void GameOfLife::setValue(const int i, const int j, const bool value)
{
	if (i < 0 || i >= m_gridSize || j < 0 || j >= m_gridSize)
	{
		std::cout << "Cell [" << i << ", " << j << "] doesn't exists" << std::endl;
	}
	else
	{
		m_grid[i * m_gridSize + j] = value;
	}
}
