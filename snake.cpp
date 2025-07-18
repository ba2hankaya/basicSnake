using namespace std;
#include "snake.h"
#include <string>

Snake::Snake(Map &map, WINDOW* mywin): map(map), mywin(mywin)
{
	SnakeNode head(0, 0);
	body.push_back(head);
}

bool Snake::isValidDir(bool inputAxis, int inputDirection) const
{
	return inputAxis != axis;
}

int Snake::changeDir(bool inputAxis, int inputDirection)
{
	if(!isValidDir(inputAxis, inputDirection)) return -1;

	axis = inputAxis;
	direction = inputDirection;
	return 1;
}

int Snake::addNode()
{
	SnakeNode s(body[body.size()-1].x, body[body.size()-1].y);
	body.push_back(s);
	nodeAdded = true;
	return 1;
}

int Snake::move()
{
	int nextPosX = body[0].x;
	int nextPosY = body[0].y;
	if(axis == 0){
		nextPosX = body[0].x + direction;
	}else{
		nextPosY = body[0].y + direction;
	}
	if(nextPosX < 0 || nextPosX > 10 || nextPosY < 0 || nextPosY > 10){
		return -1;
	}else{
		for(int i = 1; i < body.size(); i++){
			if(body[i].x == nextPosX && body[i].y == nextPosY){
				return -1;
			}
		}
	}
	int bodySize = body.size() - 1;
	for(int i = bodySize; i > 0; i--){
		if(!(body[i].x == body[i-1].x && body[i].y == body[i-1].y)){
			body[i] = body[i-1];
		}
	}

	body[0].x = nextPosX;
	body[0].y = nextPosY;


	if(map.cellHasApple(body[0].x,body[0].y)){
		addNode();
		score++;
		int appleX, appleY;
		map.eatApple(body[0].x, body[0].y);
		map.generateApple(appleX, appleY, *this);
	}
	return 1;
}

void Snake::printSnake() const
{
	for(int i = 1; i < body.size(); i++){
		mvwprintw(mywin, body[i].y+1, body[i].x+1, "$");
	}
	mvwprintw(mywin, body[0].y+1, body[0].x+1, "@");
	//mvprintw(41, 50, std::to_string(body[0].x).c_str());
	//mvprintw(41, 52, std::to_string(body[0].y).c_str());
}

int Snake::getScore() const{return score;}

int Snake::getSize() const{ return body.size();}

bool Snake::isOnCell(const int x, const int y) const{
	for(int i = 0; i < body.size(); i++){
		if(body[i].x == x && body[i].y == y){
			return true;
		}
	}
	return false;
}
