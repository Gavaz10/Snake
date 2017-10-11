#include "stdafx.h"
#include "MainMenu.h"


bool MainMenu::gameStarted()
{
	return m_gameStarted;
}

void MainMenu::endGame()
{
	m_gameOver = true;
	m_gameStarted = false;
}

void MainMenu::draw(MainWindow& window)
{
	static sf::Texture snakeTexture = loadImageFromFile("images/snake2.png");
	static sf::Sprite snakeSprite(snakeTexture);
	
	static sf::Font font = loadFontFromFile("fonts/arial.ttf");

	static sf::Text startGameText("Press SPACE to start game", font, 20);
	startGameText.setFillColor(sf::Color::Black);
	startGameText.setPosition(10.f , window.getResoulution().y / 2.f);

	static sf::Text gameOverText("GAME OVER\n Press SPACE to restart game", font, 20);
	gameOverText.setFillColor(sf::Color::Black);
	gameOverText.setPosition(10.f, window.getResoulution().y / 2.f);

	snakeSprite.setOrigin(snakeTexture.getSize().x / 2.f, snakeTexture.getSize().y / 2.f);
	snakeSprite.setPosition(window.getResoulution().x / 2.f, window.getResoulution().y / 2.f);

	window.draw(snakeSprite);
	window.draw(m_gameOver ? gameOverText : startGameText);
}

void MainMenu::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		m_gameStarted = true;
}

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}
