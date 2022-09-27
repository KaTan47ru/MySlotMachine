#include "Button.h"

void Button::draw(sf::RenderTarget& t, sf::RenderStates s) const
{

	t.draw(this->m_sprite, s);
	t.draw(this->m_text, s);
}

Button::Button(const sf::Vector2f position, const std::string buttonText)
{
	
	this->unHoverTexture.loadFromFile("assets/button.png");
	this->hoverTexture.loadFromFile("assets/buttonHov.png");

	this->state = HoverState::unHovered;

	auto size = this->unHoverTexture.getSize();
	this->m_sprite.setTexture(this->unHoverTexture);
	this->m_sprite.setOrigin(size.x / 2, size.y / 2);
	this->m_sprite.setPosition(position);
	sf::Vector2f txtPos = this->m_sprite.getPosition();
	this->m_text.setString(buttonText);
	sf::Font* titleFont = new sf::Font;
	titleFont->loadFromFile("assets/font.ttf");
	this->m_text.setFillColor(sf::Color::Black);
	this->m_text.setFont(*titleFont);
	this->m_text.setCharacterSize(25);
	std::cout << this->m_text.getLocalBounds().height << " " << this->m_text.getLocalBounds().width << std::endl;

	this->m_text.setOrigin(m_text.getLocalBounds().width/2, m_text.getGlobalBounds().height/2-size.y/2);
	this->m_text.setPosition(position);
	
	
}

void Button::checkMouse(sf::Vector2i mousePosition)
{
	auto buttonPosition = this->m_sprite.getPosition();
	auto width_2 = this->m_sprite.getGlobalBounds().width/2;
	auto height_2 = this->m_sprite.getGlobalBounds().height/2;
	if (this->state == HoverState::unHovered)
	{
		if (   mousePosition.x >= buttonPosition.x - width_2 
			&& mousePosition.x <= buttonPosition.x + width_2
			&& mousePosition.y >= buttonPosition.y - height_2 
			&& mousePosition.y <= buttonPosition.y + height_2)
		{
			this->state = HoverState::hovered;
			this->m_text.setFillColor(sf::Color::Red);
			this->m_sprite.setTexture(this->hoverTexture);
		}
	}
	else
	{
		if (   !(mousePosition.x >= buttonPosition.x - width_2)
			|| !(mousePosition.x <= buttonPosition.x + width_2)
			|| !(mousePosition.y >= buttonPosition.y - height_2)
			|| !(mousePosition.y <= buttonPosition.y + height_2))
		{
			this->state = HoverState::unHovered;
			this->m_text.setFillColor(sf::Color::Black);
			this->m_sprite.setTexture(this->unHoverTexture);
		}
	}
}

void Button::hovered()
{
	if (this->state == HoverState::unHovered)
	{
		this->m_sprite.setTexture(this->hoverTexture);
		this->state = HoverState::hovered;
	}
}

void Button::unHovered()
{
	if (this->state == HoverState::hovered)
	{
		this->m_sprite.setTexture(this->unHoverTexture);
		this->state = HoverState::unHovered;
	}
}
