#include "map.h"
#include <random>
#include <ncurses.h>
#include <string>
Map::Map()
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			mp[i][j] = 0;
		}
	}
}

void getRandomLoc(int &x, int &y)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1.0,10.0);
	x = dist(mt);
	y = dist(mt);
}

void Map::generateApple(int &x, int &y)
{
	int myX, myY;
	getRandomLoc(myX, myY);
	mp[myY][myX] = 1;
	x = myX;
	y = myY;
}

bool Map::cellHasApple(const int x, const int y)
{
	return mp[y][x] == 1;
}

void Map::eatApple(const int x, const int y)
{
	mp[y][x] = 0;
}

void Map::printMap()
{
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 10; x++){
			if(mp[y][x] == 1)
			{
				mvprintw(y, x, "Q");
				mvprintw(40, 50, std::to_string(x).c_str());
				mvprintw(40, 52, std::to_string(y).c_str());
			}
		}
	}
}


