#ifndef MAP_H
#define MAP_H

class Map
{
	private:
		int mp[10][10];
		char apple = 'Q';
	public:
		Map();
		void generateApple(int& x, int& y);
		void printMap();
		bool cellHasApple(const int x ,const int y);
		void eatApple(const int x, const int y);
};

#endif
