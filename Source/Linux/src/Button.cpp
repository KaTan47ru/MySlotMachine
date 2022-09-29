#include "Button.h"
// Переопределение унаследованного метода для рисования
void Button::draw(sf::RenderTarget& t, sf::RenderStates s) const
{

	t.draw(this->buttonSprite, s);
	t.draw(this->textTitle, s);
}
// Конструктор, выставляются совйства кнопки: размер, позиция, якорь
Button::Button(const sf::Vector2f position, const std::string buttonText)
{
	
	this->unHoverTexture.loadFromFile("assets/button.png");
	this->hoverTexture.loadFromFile("assets/buttonHov.png");

	this->state = HoverState::unHovered;

	auto size = this->unHoverTexture.getSize();
	this->buttonSprite.setTexture(this->unHoverTexture);
	this->buttonSprite.setOrigin(size.x / 2, size.y / 2);
	this->buttonSprite.setPosition(position);
	sf::Vector2f txtPos = this->buttonSprite.getPosition();
	this->textTitle.setString(buttonText);
	textFont = new sf::Font;
	textFont->loadFromFile("assets/font.ttf");
	this->textTitle.setFillColor(sf::Color::Black);
	this->textTitle.setFont(*textFont);
	this->textTitle.setCharacterSize(25);
	

	this->textTitle.setOrigin(textTitle.getLocalBounds().width/2, textTitle.getGlobalBounds().height/2-size.y/2);
	this->textTitle.setPosition(position);
	
	
}
// Проверка для свойства :hovered. Если наведена мвшка, меняется текстурка
void Button::checkMouse(sf::Vector2i mousePosition)
{
	auto buttonPosition = this->buttonSprite.getPosition();
	auto l = this->buttonSprite.getGlobalBounds().left;
	auto t = this->buttonSprite.getGlobalBounds().top;
	
	auto width = this->buttonSprite.getGlobalBounds().width;
	auto height = this->buttonSprite.getGlobalBounds().height;

	if (this->state == HoverState::unHovered)
	{
		if (   mousePosition.x >= l
			&& mousePosition.x <= l + width
			&& mousePosition.y >= t 
			&& mousePosition.y <= t + height)
		{
			this->state = HoverState::hovered;
			this->textTitle.setFillColor(sf::Color::Red);
			this->buttonSprite.setTexture(this->hoverTexture);
		}
	}
	else
	{
		if (   !(mousePosition.x >= l)
			|| !(mousePosition.x <= l + width)
			|| !(mousePosition.y >= t)
			|| !(mousePosition.y <= t + height))
		{
			this->state = HoverState::unHovered;
			this->textTitle.setFillColor(sf::Color::Black);
			this->buttonSprite.setTexture(this->unHoverTexture);
		}
	}
}
// Проверка на нажате tre - нажата, иначе false
bool Button::checkMousePressed(sf::Vector2i mousePosition)
{
	auto buttonPosition = this->buttonSprite.getPosition();
	auto width_2 = this->buttonSprite.getGlobalBounds().width / 2;
	auto height_2 = this->buttonSprite.getGlobalBounds().height / 2;
	
	if (mousePosition.x >= buttonPosition.x - width_2
		&& mousePosition.x <= buttonPosition.x + width_2
		&& mousePosition.y >= buttonPosition.y - height_2
		&& mousePosition.y <= buttonPosition.y + height_2)
	{
		return true;
	}
	else
		return false;
	
}

Button::~Button()
{
	delete this->textFont;
}

