#pragma once

enum Direction : int
{
	UP = 0, RIGHT, DOWN, LEFT
};

#define GAME_NAME "SNAKE"

#define SNAKE_FIELD_SIZE_X 20
#define SNAKE_FIELD_SIZE_Y 20

#define SNAKE_FIELD_CEIL_SIZE_X 15
#define SNAKE_FIELD_CEIL_SIZE_Y 15

#define ONE_TICK_TIME 100