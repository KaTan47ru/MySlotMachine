#pragma once
#include <SFML/Graphics.hpp>
class Button : public sf::Drawable
{
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	Button(const sf::Vector2f position,const std::string buttonText);
private:
	sf::Sprite m_sprite;
	sf::Text m_text;
	sf::Texture m_texture;
};

