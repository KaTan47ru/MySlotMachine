#include "Symbol.h"
// Конструктор. Установка свойств сивола: его числового индекса, позиции на экране, текстуры.
Symbol::Symbol(std::string texturePath, sf::Vector2f basePosition, int index)
{
	this->symbolIndex = index;
	this->symbolTexture = new sf::Texture;
	if (this->symbolTexture->loadFromFile(texturePath))
	{
		this->symbolShape = sf::RectangleShape({ 100,100 });
		this->symbolShape.setOrigin({ 50,50 });

		this->symbolShape.setTexture(this->symbolTexture);
		this->symbolShape.move(basePosition.x, basePosition.y);
	}
}
// Конструктор копирования. Нужен для корректной работы Slt контейнеров.
Symbol::Symbol(const Symbol& other)
{
	this->symbolShape = sf::RectangleShape(other.symbolShape);
	this->symbolTexture = new sf::Texture(*other.symbolTexture);
	this->symbolIndex = other.symbolIndex;
	
}
// Переоределения метода draw
void Symbol::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
	t.draw(this->symbolShape, s);
}
// Метод получения позиции символа на эеране.
sf::Vector2f Symbol::getPosition()
{
	return this->symbolShape.getPosition();
}

void Symbol::setPosition(sf::Vector2f newPosition)
{
	this->symbolShape.setPosition(newPosition);
}

int Symbol::getIndex() const
{
	return this->symbolIndex;
}



Symbol::~Symbol()
{

	delete this->symbolTexture;
}







