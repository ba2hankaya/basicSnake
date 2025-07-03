using namespace std;
#include "snake.h"
#include <string>

Snake::Snake(Map &map): map(map)
{
	SnakeNode head(0, 0);
	body.push_back(head);
}

int Snake::changeDir(bool inputAxis, int inputDirection)
{
	if(inputAxis == axis)
	{
		return -1;
	}
	else
	{
		axis = inputAxis;
		direction = inputDirection;
		return 1;
	}
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
	int bodySize = body.size() - 1;
	if(nodeAdded)
	{
		bodySize--;
		nodeAdded = false;
	}
	for(int i = bodySize; i > 0; i--){
		body[i] = body[i-1];
	}
	if(body[0].x < 0 || body[0].x > 10 || body[0].y < 0 || body[0].y > 10){
		return -1;
	}
	if(axis == 0){
		body[0].x += direction;
	}else{
		body[0].y += direction;
	}
	if(map.cellHasApple(body[0].x,body[0].y)){
		addNode();
		int appleX, appleY;
		map.eatApple(body[0].x, body[0].y);
		map.generateApple(appleX, appleY);
	}
	return 1;
}

void Snake::printSnake()
{
	for(int i = 1; i < body.size(); i++){
		mvprintw(body[i].y, body[i].x, "$");
	}
	mvprintw(body[0].y, body[0].x, "@");
	mvprintw(41, 50, std::to_string(body[0].x).c_str());
	mvprintw(41, 52, std::to_string(body[0].y).c_str());
}



