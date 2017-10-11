#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow()
{
	mainWindow.create({ 640, 480 }, GAME_NAME, sf::Style::Close | sf::Style::Titlebar);
}


MainWindow::~MainWindow()
{

}

void MainWindow::startFrame()
{
	mainWindow.clear();
}

void MainWindow::draw(sf::Drawable& item)
{
	mainWindow.draw(item);
}

void MainWindow::endFrame()
{
	mainWindow.display();
}

bool MainWindow::isOpen()
{
	return mainWindow.isOpen();
}

void MainWindow::checkEvents()
{
	sf::Event event;
	while (mainWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			onClose();

	}
}

void MainWindow::setResolution(sf::Vector2u res)
{
	mainWindow.create({res.x, res.y}, GAME_NAME, sf::Style::Close | sf::Style::Titlebar);
}

sf::Vector2u MainWindow::getResoulution()
{
	return mainWindow.getSize();
}

void MainWindow::onClose()
{
	mainWindow.close();
}