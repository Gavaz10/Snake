#include "stdafx.h"
#include "Snake.h"


void Snake::drawCeil(int x, int y, MainWindow& window, int ceilState)
{
	sf::RectangleShape shape({SNAKE_FIELD_CEIL_SIZE_X, SNAKE_FIELD_CEIL_SIZE_Y});
	sf::Color color;
	switch (ceilState)
	{
	default:
		break;
	case EMPTY:
		color = sf::Color::Black;
		break;
	case FILLED:
		color = sf::Color::White;
		break;
	case HEAD:
		color = sf::Color::Green;
		break;
	case APPLE:
		color = sf::Color::Red;
		break;
	}

	shape.setFillColor(color);
	shape.setOutlineThickness(1.0f);
	shape.setOutlineColor(sf::Color::White);
	shape.setPosition((SNAKE_FIELD_CEIL_SIZE_X + 1.f) * x, (SNAKE_FIELD_CEIL_SIZE_Y + 1.f) * y);
	window.draw(shape);
}

void Snake::setDirection(Direction direction)
{
	this->direction = direction;
}

bool Snake::checkColision(MainMenu& menu)
{
	std::pair<int, int> futurePos;

	switch (direction)
	{
	case UP:
		if (snakeBody[0].second == 0)
			endGame(menu);
		futurePos = std::make_pair(snakeBody[0].first, snakeBody[0].second - 1);
		break;
	case RIGHT:
		if (snakeBody[0].first == SNAKE_FIELD_SIZE_X - 1)
			endGame(menu);
		futurePos = std::make_pair(snakeBody[0].first + 1, snakeBody[0].second);
		break;
	case LEFT:
		if (snakeBody[0].first == 0)
			endGame(menu);
		futurePos = std::make_pair(snakeBody[0].first - 1, snakeBody[0].second);
		break;
	case DOWN:
		if (snakeBody[0].second == SNAKE_FIELD_SIZE_Y - 1)
			endGame(menu);
		futurePos = std::make_pair(snakeBody[0].first, snakeBody[0].second + 1);
		break;
	}


	if (ceilInSnakeBodyExceptLast(futurePos))
		endGame(menu);
	

	if (futurePos == applePosition)
	{
		snakeBody.push_back(std::make_pair(0, 0));
		for (int i = snakeBody.size() - 1; i > 0; i--)
		{
			snakeBody[i] = snakeBody[i - 1];
		}
		snakeBody[0] = applePosition;
		updateApplePosition();
		return false;
	}
	return true;
}

void Snake::move()
{
	for (int i = snakeBody.size() - 1; i > 0; i--)
	{
		snakeBody[i] = snakeBody[i - 1];
	}
	switch (direction)
	{
	case UP:
		snakeBody[0].second--;
		break;
	case RIGHT:
		snakeBody[0].first++;
		break;
	case LEFT:
		snakeBody[0].first--;
		break;
	case DOWN:
		snakeBody[0].second++;
		break;
	}
}

void Snake::updateApplePosition()
{
	do
	{
		applePosition = std::make_pair(rand() % SNAKE_FIELD_SIZE_Y, rand() % SNAKE_FIELD_SIZE_X);
	} 
	while (ceilInSnakeBody(applePosition));
}

bool Snake::ceilInSnakeBody(int x, int y)
{
	for (auto ceil : snakeBody)
	{
		if (ceil == std::make_pair(x, y))
			return true;
	}
	return false;
}

bool Snake::ceilInSnakeBodyExceptLast(int x, int y)
{
	for (unsigned int i = 0; i < snakeBody.size() - 1; i++)
	{
		if (snakeBody[i] == std::make_pair(x, y))
			return true;
	}
	return false;
}

bool Snake::ceilInSnakeBody(std::pair<int, int> pos)
{
	for (auto ceil : snakeBody)
	{
		if (ceil == pos)
			return true;
	}
	return false;
}

bool Snake::ceilInSnakeBodyExceptLast(std::pair<int, int> pos)
{
	for (unsigned int i = 0; i < snakeBody.size() - 1; i++)
	{
		if (snakeBody[i] == pos)
			return true;
	}
	return false;
}

void Snake::endGame(MainMenu& menu)
{
	snakeBody = { {5,5}, {5,6} };
	updateApplePosition();
	menu.endGame();
}

void Snake::update(MainMenu& menu)
{
	static sf::Clock clock;
	if (clock.getElapsedTime().asMilliseconds() < ONE_TICK_TIME)
		return;
	static Direction lastDirection = direction;
	if (abs(lastDirection - this->direction) == 2)
	{
		this->direction = lastDirection;
	}
	else
	{
		lastDirection = this->direction;
	}
	clock.restart();
	if(checkColision(menu))
		move();
}

void Snake::draw(MainWindow& window)
{
	for (int i = 0; i < SNAKE_FIELD_SIZE_Y; i++)
	{
		for (int j = 0; j < SNAKE_FIELD_SIZE_X; j++)
		{
			drawCeil(j, i, window, EMPTY);
		}
	}

	for (unsigned int i = 0; i < snakeBody.size(); i++)
	{
		int state = i == 0 ? HEAD : FILLED;
		drawCeil(snakeBody[i].first, snakeBody[i].second, window, state);
	}

	drawCeil(applePosition.first, applePosition.second, window, APPLE);
}

Snake::Snake()
{
	snakeBody.push_back(std::make_pair(5, 5));
	snakeBody.push_back(std::make_pair(5, 6));
	updateApplePosition();
}


Snake::~Snake()
{
}