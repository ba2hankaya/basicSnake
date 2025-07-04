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
	double time = 0;

	int ch;
	int firstAppleX, firstAppleY;
	map.generateApple(firstAppleX, firstAppleY);
	bool axis = 0;
	int direction = 1;
	while(true){
		ch = getch();
		if(ch != ERR){
			if(ch == 'q') break;
			switch(ch)
			{
				case KEY_UP:
					axis = 1;
					direction = -1;
					break;
				case KEY_DOWN:
					axis = 1;
					direction = 1;
					break;
				case KEY_LEFT:
					axis = 0;
					direction = -1;
					break;
				case KEY_RIGHT:
					axis = 0;
					direction = 1;
					break;
			}
		}
		timer.update();
		if(timer.getTime() - 0.3 >= time){
			clear();
			mvwvline(stdscr, 0, 11, ACS_VLINE, 11);
			mvwhline(stdscr, 11, 0, ACS_HLINE, 11);
			time = timer.getTime();
			const string timeStr = "Time: " + std::to_string((int)time);
			mvprintw(0,13, timeStr.c_str());
			s1.changeDir(axis, direction);
			int result = s1.move();
			if(result == -1) break;
			map.printMap();
			s1.printSnake();
			const string curScore = "Score: " + std::to_string(s1.getScore());
			mvprintw(1,13, curScore.c_str()); 
			refresh();
		}

		usleep(10000);
	}

	mvprintw(5, 0, "The game has ended.");
	const string score = "Your score was " + std::to_string(s1.getScore());
	mvprintw(6, 0, score.c_str());

	while(true){
		ch = getch();
		if(ch != ERR){
			if(ch == 'q') break;
		}
		usleep(100000);
	}

	endwin();

	return 0;
}
