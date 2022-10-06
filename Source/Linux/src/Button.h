#pragma once
#include "SFML/Graphics.hpp"

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
	Button(const sf::Vector2f & position,const std::string& buttonText);
	void checkMouse(const sf::Vector2i&);
	bool checkMousePressed(const sf::Vector2i&) const;
	~Button();
private:
	

	HoverState state;
	sf::Texture hoverTexture;
	sf::Texture unHoverTexture;
	sf::Sprite buttonSprite;
	sf::Text textTitle;
	sf::Font *textFont;

};
