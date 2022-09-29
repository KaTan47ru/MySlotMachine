#pragma once
#include <SFML/Graphics.hpp>
// Интерфейс для Сотсояний. Было решено для каждого определить совю процедуру обработки машины
// Хотел сделать абстактный базовый класс с двумя полями, но это не подхожит под определение Интерфейс, поэтому у каждого состояния они определены по потдельности.
class State
{

public:
	virtual void runRoutine(sf::RenderWindow* window) = 0;
	virtual void setNextState(State * next) = 0;
};

