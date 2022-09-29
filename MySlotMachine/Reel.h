#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include "Symbol.h"
#include <list>
class Reel:public sf::Drawable
{
private:

	float speed;
	std::pair<float,float> timeToSpin;
	sf::Vector2f basePosition;
	static Symbol* getNewSymbol(sf::Vector2f);
	std::list<Symbol *> m_symbs;
	float acceleration;
	bool isSpining;
public:
	int getStatus();
	Reel(sf::Clock&, float, sf::Vector2f, bool);
	void stop();
	std::array<int, 5> getSymbolsNew() const;
	bool updateNew(float);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void spin(float);

};

