#pragma once
class MainMenu
{
private:
	bool m_gameStarted = false;
	bool m_gameOver = false;

public:
	bool gameStarted();
	void endGame();
	void draw(MainWindow&);
	void update();
	MainMenu();
	~MainMenu();
};

