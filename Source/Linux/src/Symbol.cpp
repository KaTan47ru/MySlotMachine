#include "Symbol.h"
// �����������. ��������� ������� ������: ��� ��������� �������, ������� �� ������, ��������.
Symbol::Symbol( const std::string & texturePath,const  sf::Vector2f & basePosition,const int & index)
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
// ����������� �����������. ����� ��� ���������� ������ Slt �����������.
Symbol::Symbol(const Symbol& other)
{
	this->symbolShape = sf::RectangleShape(other.symbolShape);
	this->symbolTexture = new sf::Texture(*other.symbolTexture);
	this->symbolIndex = other.symbolIndex;
	
}
// �������������� ������ draw
void Symbol::draw(sf::RenderTarget& t, sf::RenderStates s) const
{
	t.draw(this->symbolShape, s);
}
// ����� ��������� ������� ������� �� ������.
sf::Vector2f Symbol::getPosition()
{
	return this->symbolShape.getPosition();
}

void Symbol::setPosition(const sf::Vector2f & newPosition)
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







