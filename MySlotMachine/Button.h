#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Button : public sf::Drawable
{
public:
	enum class HoverState
	{
		hovered,
		unHovered
	};
	
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	Button(const sf::Vector2f position,const std::string buttonText);
	void checkMouse(sf::Vector2i);
	bool checkMousePressed(sf::Vector2i);
private:
	
	void hovered();
	void unHovered();
	HoverState state;
	sf::Texture hoverTexture;
	sf::Texture unHoverTexture;
	sf::Sprite m_sprite;
	sf::Text m_text;

};

