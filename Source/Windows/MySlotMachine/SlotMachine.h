#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "ReelWrapper.h"
// Класс для машины, которая будет управляться состояниями
class SlotMachine
{
private:
	// Контейнер с элементами статичного интерфейса
	std::vector<sf::Drawable *> staticDrawables;
	// Контейнер с текстурами
	std::vector<sf::Texture*> textures;
	// Конпка начать
	Button * startButton;
	// Кнопка стоп
	Button * stopButton;
	// Барабан
	ReelWrapper * drumb;
	// Поля с динамическимтекстом
	sf::Text* helpText;
	sf::Text* prizeValue;
	// Шрифт Хранить надо, потому что в локальной переменной не работает
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

