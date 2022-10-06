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

	static Symbol* getNewSymbol(const sf::Vector2f &);
public:
	Reel(const  float &,const sf::Vector2f &, const bool &);
	Reel(const Reel& other);
	std::array<int, 5> getSymbolsNew() const;
	void stop();
	void spin(const float&);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	bool updateNew(const float&);
	int getStatus();
	~Reel();

};

