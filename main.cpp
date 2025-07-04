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
	curs_set(0);
	WINDOW* gamewin = newwin(13,13,0,0);
	nodelay(gamewin, TRUE);
	keypad(gamewin, TRUE);
	Map map(gamewin);
	Snake s1(map, gamewin);
	s1.printSnake();
	Timer timer;
	double time = 0;

	int ch;
	int firstAppleX, firstAppleY;
	map.generateApple(firstAppleX, firstAppleY, s1);
	bool axis = 0;
	int direction = 1;
	while(true){
		ch = wgetch(gamewin);
		if(ch != ERR){
			if(ch == 'q') break;
			switch(ch)
			{
				case KEY_UP:
					if(s1.isValidDir(1, -1)){
						axis = 1;
						direction = -1;
					}
					break;
				case KEY_DOWN:
					if(s1.isValidDir(1,1)){
						axis = 1;
						direction = 1;
					}
					break;
				case KEY_LEFT:
					if(s1.isValidDir(0, -1)){
						axis = 0;
						direction = -1;
					}
					break;
				case KEY_RIGHT:
					if(s1.isValidDir(0, 1)){
						axis = 0;
						direction = 1;
					}
					break;
			}
		}
		timer.update();
		if(timer.getTime() - 0.3 >= time){
			clear();
			wclear(gamewin);
			//mvwvline(stdscr, 0, 11, ACS_VLINE, 11);
			//mvwhline(stdscr, 11, 0, ACS_HLINE, 11);
			//mvaddch(11 , 11, ACS_LRCORNER);
			box(gamewin, 0, 0);

			const string curScore = "Score: " + std::to_string(s1.getScore());
			mvprintw(1,14, curScore.c_str()); 

			time = timer.getTime();
			const string timeStr = "Time: " + std::to_string((int)time);
			mvprintw(0,14, timeStr.c_str());


			s1.changeDir(axis, direction);
			int result = s1.move();
			if(result == -1) break;

			map.printMap();
			s1.printSnake();

			refresh();
			wrefresh(gamewin);

		}

		usleep(10000);
	}

	mvprintw(5, 14, "The game has ended.");
	const string score = "Your score was " + std::to_string(s1.getScore());
	mvprintw(6, 14, score.c_str());
	refresh();
	map.printMap();
	s1.printSnake();
	wrefresh(gamewin);
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
