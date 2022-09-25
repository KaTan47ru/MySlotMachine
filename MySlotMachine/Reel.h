#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Reel:public sf::Drawable
{
private:
	std::vector<std::pair<sf::Sprite, sf::Texture*>> reelObjects;
	float speed;
	float timeToSpin;
	int anchor = 0;
	sf::Vector2f basePosition;
	static std::pair<sf::Sprite, sf::Texture*> getNextSymbol(sf::Vector2f basePosition);

public:

	Reel(sf::Clock&, float, sf::Vector2f );
	void update(float time);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void spin(float);

};

