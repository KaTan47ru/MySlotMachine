#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include "Symbol.h"
#include <list>
// Класс сеализующий столбец барабана.
// Каждый столбец содержит 7 символов. 
// Первый и седьмой не видны игроку. Нужны для плавности движения.
class Reel:public sf::Drawable
{
private:

	// Контейнер с символами
	std::list<Symbol*> reelSymbols;
	// Контейнер с временем вращения
	std::pair<float,float> timeToSpin;
	// Верхняя централь первого элемента барабана
	sf::Vector2f basePosition;
	// Ускорене
	float acceleration;
	// Скорость
	float speed;
	// Флаг вращения
	bool isSpining;

	static Symbol* getNewSymbol(sf::Vector2f);
public:
	Reel( float, sf::Vector2f, bool);
	Reel(const Reel& other);
	std::array<int, 5> getSymbolsNew() const;
	void stop();
	void spin(float);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	bool updateNew(float);
	int getStatus();
	~Reel();

};

