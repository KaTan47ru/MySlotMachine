#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
// Класс для интерактивных элементов в стиле кнопки.
// Реагирует на щелчок - возвращает true/false если щелчек был произведен в ее кординатах
// Также есть реализация свойства :hovered. При срабатывании меняет текстурку.
class Button : public sf::Drawable
{
public:
	// Эномерация для отслеживания состояний кнопки, так при наведении на кнопу можно сэкономить на проверке
	enum class HoverState
	{
		hovered,
		unHovered
	};
	
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	Button(const sf::Vector2f position,const std::string buttonText);
	void checkMouse(sf::Vector2i);
	bool checkMousePressed(sf::Vector2i);
	~Button();
private:
	

	HoverState state;
	sf::Texture hoverTexture;
	sf::Texture unHoverTexture;
	sf::Sprite buttonSprite;
	sf::Text textTitle;
	sf::Font *textFont;

};

