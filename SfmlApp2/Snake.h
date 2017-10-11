#include "stdafx.h"
#pragma once
class Snake
{
private:
	Direction direction = UP;
	std::pair<int, int> applePosition;
	std::vector<std::pair<int, int> > snakeBody;

	void drawCeil(int x, int y, MainWindow& window, int ceilState);
	bool checkColision(MainMenu&);
	void move();
	void updateApplePosition();
	bool ceilInSnakeBody(int x, int y);
	bool ceilInSnakeBody(std::pair<int, int> pos);
	bool ceilInSnakeBodyExceptLast(int x, int y);
	bool ceilInSnakeBodyExceptLast(std::pair<int, int> pos);
	
	void endGame(MainMenu&);
	
	enum CeilStates{ EMPTY = 0, FILLED, HEAD, APPLE };
	
	
public:
	void setDirection(Direction);
	void update(MainMenu&);
	void draw(MainWindow&);
	Snake();
	~Snake();
};

