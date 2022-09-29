#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
class Symbol : public sf::Drawable
{
public:

	Symbol(std::string texturePath, sf::Vector2f basePosition,int index);
	Symbol(const Symbol& other);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	int getIndex() const;
	virtual ~Symbol();
private:
	sf::Texture * symbolTexture;
	sf::RectangleShape symbolShape;
	int symbolIndex;
};

