# GameOfLife

Implementation of the John Conway’s Game of Live using OpenFrameworks (C++).

<p align="center">
<img src="https://github.com/Ahziel/GameOfLife/blob/master/example.gif" width="400" height="400" />
</p>

## Description

The Game of Life is a cellular automaton created by the Cambridge mathematician John Horton Conway in 1970. Even though it is called “Game of Life”, this program is NOT A GAME but only an automaton. The behaviour of the program is determined by the initial state of the system/grid and a set of rules.

## Rules

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead. The state of a cell is defined by its eights neighbours (up, down, left, rights and the four diagonals). At each step, we modify each cell at the same time. The rules are :

* Any live cell with fewer than two live neighbours dies, as if by underpopulation.
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies, as if by overpopulation.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## Use

Create a new project with the project generator of OpenFrameworks and replace the files of your project with the files from this repository.

### Commands

* Key N : Create a new grid with a random initialization
* Key B : Create a new grid full of dead cell
* Key P : Pause/Play
* Mouse Pressed : Chance the state of the cell 

## Sources

Wikipedia : https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

