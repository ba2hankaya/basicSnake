#ifndef MAP_H
#define MAP_H

#include <ncurses.h>

class Snake;

class Map
{
	private:
		int mp[10][10];
		char apple = 'Q';
		WINDOW* mywin;
	public:
		Map(WINDOW* mywin);
		void generateApple(int& x, int& y, const Snake& s);
		void printMap() const;
		bool cellHasApple(const int x ,const int y) const;
		void eatApple(const int x, const int y);
};

#endif
