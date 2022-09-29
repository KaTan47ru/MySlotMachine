#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "ReelWrapper.h"
class SlotMachine
{
private:
	bool drawMesh;
	std::vector<sf::RectangleShape*> mesh;
	std::vector<sf::Drawable *> m_static;
	Button * startButton;
	Button * stopButton;
	ReelWrapper * m_reels;
	sf::Text* helpText;
	sf::Text* prizeValue;
	sf::Font * textFont;

public:
	SlotMachine();
	void spin();
	void stop();
	void processPrize();
	void dropMachine();
	bool render(sf::RenderWindow* window);
	void trackMouse(sf::Vector2i mousePosition);
	bool trackStartClicks(sf::Vector2i mousePosition);
	bool trackStopClicks(sf::Vector2i mousePosition);
	~SlotMachine();
};

