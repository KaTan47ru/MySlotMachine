#pragma once
#include "SFML/Graphics.hpp"
#include <string>
// ����� ��� ������� � �������
class Symbol : public sf::Drawable
{
public:

	Symbol(const std::string & texturePath ,const sf::Vector2f& basePosition,const int& index);
	Symbol(const Symbol& other);
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f &);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	int getIndex() const;
	virtual ~Symbol();
private:
	// �������� �������, ���� ������� ����������, ��� ��� ����� �� ��������������
	sf::Texture * symbolTexture;
	sf::RectangleShape symbolShape;
	int symbolIndex;
};

