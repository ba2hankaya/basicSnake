#ifndef SNAKE_H
#define SNAKE_H

#include <ncurses.h>
#include <vector>
#include "map.h"
using namespace std;

class Snake
{
	private:
		struct SnakeNode
		{
			int x;
			int y;
			SnakeNode(int inputX, int inputY): x(inputX), y(inputY){}
		};
		bool nodeAdded = false;
		bool axis = 0;
		int direction = 1;
		vector<SnakeNode> body;
		Map &map;
		int score = 0;
	public:
		Snake(Map &map);

		int changeDir(bool inputAxis, int inputDirection);

		int move();

		void printSnake();

		int addNode();

		int getScore();

};

#endif
