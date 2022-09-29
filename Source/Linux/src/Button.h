#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
// ����� ��� ������������� ��������� � ����� ������.
// ��������� �� ������ - ���������� true/false ���� ������ ��� ���������� � �� ����������
// ����� ���� ���������� �������� :hovered. ��� ������������ ������ ���������.
class Button : public sf::Drawable
{
public:
	// ���������� ��� ������������ ��������� ������, ��� ��� ��������� �� ����� ����� ���������� �� ��������
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
