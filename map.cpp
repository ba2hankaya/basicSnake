#include "map.h"
#include <random>
#include <ncurses.h>
#include <string>
#include "snake.h"
Map::Map(WINDOW* mywin): mywin(mywin)
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			mp[i][j] = 0;
		}
	}
}

int getRandomNum(const int min,const int maxExcluded)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(min,maxExcluded);
	return dist(mt);
}

void Map::generateApple(int &x, int &y,const Snake &s)
{
	int max = s.getSize();
	int rawLoc = getRandomNum(0, 100-max);
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(!s.isOnCell(j, i)){
				if(rawLoc == 0){
					mp[i][j] = 1;
					x = j;
					y = i;
					return;
				}
				rawLoc--;
			}
		}
	}
}

bool Map::cellHasApple(const int x, const int y) const
{
	return mp[y][x] == 1;
}

void Map::eatApple(const int x, const int y)
{
	mp[y][x] = 0;
}

void Map::printMap() const
{
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 10; x++){
			if(mp[y][x] == 1)
			{
				mvwprintw(mywin, y, x, "Q");
				//mvprintw(40, 50, std::to_string(x).c_str());
				//mvprintw(40, 52, std::to_string(y).c_str());
			}
		}
	}
}


