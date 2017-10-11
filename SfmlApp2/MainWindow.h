#pragma once
#include "stdafx.h"

class MainWindow
{
private:
	sf::RenderWindow mainWindow;

public:
	MainWindow();
	~MainWindow();
	void startFrame();
	void draw(sf::Drawable&);
	void endFrame();
	bool isOpen();
	void checkEvents();
	void setResolution(sf::Vector2u);
	sf::Vector2u getResoulution();

private:
	void onClose();
};