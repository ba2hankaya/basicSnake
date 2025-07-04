#ifndef MAP_H
#define MAP_H

class Snake;

class Map
{
	private:
		int mp[10][10];
		char apple = 'Q';
	public:
		Map();
		void generateApple(int& x, int& y, const Snake& s);
		void printMap();
		bool cellHasApple(const int x ,const int y);
		void eatApple(const int x, const int y);
};

#endif
