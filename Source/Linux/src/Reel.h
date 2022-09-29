#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <array>
#include "Symbol.h"
#include <list>
// ����� ����������� ������� ��������.
// ������ ������� �������� 7 ��������. 
// ������ � ������� �� ����� ������. ����� ��� ��������� ��������.
class Reel:public sf::Drawable
{
private:

	// ��������� � ���������
	std::list<Symbol*> reelSymbols;
	// ��������� � �������� ��������
	std::pair<float,float> timeToSpin;
	// ������� �������� ������� �������� ��������
	sf::Vector2f basePosition;
	// ��������
	float acceleration;
	// ��������
	float speed;
	// ���� ��������
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

