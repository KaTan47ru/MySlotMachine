#include "Button.h"

void Button::draw(sf::RenderTarget& t, sf::RenderStates s) const
{

}

Button::Button(const sf::Vector2f position, const std::string buttonText)
{
	this->m_texture.loadFromFile("assets/button.png");
	auto size = this->m_texture.getSize();
	this->m_sprite.setTexture(this->m_texture);
	this->m_sprite.setOrigin(size.x / 2, size.y / 2);
	

}
