#include <ncurses.h>
#include "snake.h"
#include "timer.h"
#include <unistd.h>
#include <string>
#include "map.h"
int main(int argc, char ** argv)
{
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	Map map;
	Snake s1(map);
	s1.printSnake();
	Timer timer;
	int time = 0;

	int ch;
	int firstAppleX, firstAppleY;
	map.generateApple(firstAppleX, firstAppleY);
	while(true){
		ch = getch();
		if(ch != ERR){
			if(ch == 'q') break;
			switch(ch)
			{
				case KEY_UP:
					s1.changeDir(1 , -1);
					break;
				case KEY_DOWN:
					s1.changeDir(1 , 1);
					break;
				case KEY_LEFT:
					s1.changeDir(0 , -1);
					break;
				case KEY_RIGHT:
					s1.changeDir(0 , 1);
					break;
			}
		}
		timer.update();
		mvprintw(40,40, to_string(time).c_str());
		if(timer.getTime() - 1 >= time){
			clear();
			time = timer.getTime();
			mvprintw(40,40, to_string(time).c_str());
			s1.move();
			map.printMap();
			s1.printSnake();
			refresh();
		}

		usleep(10000);
	}
	endwin();

	return 0;
}
