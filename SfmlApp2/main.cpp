// main.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"

int main()
{
	srand((unsigned int)time(0));
	MainWindow window;
	MainMenu menu;
	window.setResolution({ (SNAKE_FIELD_CEIL_SIZE_X + 1) * SNAKE_FIELD_SIZE_X, (SNAKE_FIELD_CEIL_SIZE_Y + 1) * SNAKE_FIELD_SIZE_Y });
	Snake snake;

	while (window.isOpen())
	{
		window.startFrame();

		window.checkEvents();


		if (menu.gameStarted())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				snake.setDirection(UP);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				snake.setDirection(RIGHT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				snake.setDirection(DOWN);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				snake.setDirection(LEFT);

			snake.update(menu);
			snake.draw(window);
		}
		else
		{
			menu.update();
			menu.draw(window);
		}
		

		window.endFrame();
	}

    return 0;
}

