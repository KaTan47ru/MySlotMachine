#include "Symbol.h"

Symbol::Symbol(std::string texturePath, sf::Vector2f basePosition, int index)
{
	this->m_index = index;
	this->m_texture = new sf::Texture;
	if (this->m_texture->loadFromFile(texturePath))
	{
		this->m_shape = sf::RectangleShape({ 100,100 });
		this->m_shape.setOrigin({ 50,50 });

		this->m_shape.setOutlineColor(sf::Color::Red);
		this->m_shape.setOutlineThickness(2);
		this->m_shape.setTexture(this->m_texture);
		this->m_shape.move(basePosition.x, basePosition.y);
	}
}

Symbol::Symbol(const Symbol& other)
{
	this->m_shape = sf::RectangleShape(other.m_shape);
	this->m_texture = new sf::Texture(*other.m_texture);
	this->m_index = other.m_index;
	
}

void Symbol::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
	t.draw(this->m_shape, s);
}

sf::Vector2f Symbol::getPosition()
{
	return this->m_shape.getPosition();
}

void Symbol::setPosition(sf::Vector2f newPosition)
{
	this->m_shape.setPosition(newPosition);
}

int Symbol::getIndex() const
{
	return this->m_index;
}



Symbol::~Symbol()
{

	delete this->m_texture;
}







