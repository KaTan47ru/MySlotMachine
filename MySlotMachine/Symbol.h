#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
class Symbol : public sf::Drawable
{
public:

	Symbol(std::string texturePath, sf::Vector2f basePosition,int index);
	Symbol(const Symbol& other);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);
	int getIndex() const;
	virtual ~Symbol();
private:
	sf::Texture * m_texture;
	sf::RectangleShape m_shape;
	int m_index;
};

