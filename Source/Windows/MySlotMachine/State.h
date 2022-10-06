#pragma once
#include "SFML/Graphics.hpp"
// ��������� ��� ���������. ���� ������ ��� ������� ���������� ���� ��������� ��������� ������
// ����� ������� ���������� ������� ����� � ����� ������, �� ��� �� �������� ��� ����������� ���������, ������� � ������� ��������� ��� ���������� �� ������������.
class State
{

public:
	virtual void runRoutine(sf::RenderWindow* window) = 0;
	virtual void setNextState(State * next) = 0;
};

