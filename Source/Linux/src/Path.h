#pragma once
#include <array>
#include <vector>
#include "SFML/Graphics.hpp"
// ��������� ��� ����� ������� ����. ���������� ����������� �������� �����, � � ����� ���� ��� ����� ������� ����������.
class Path
{
public:

	virtual std::vector<std::pair<sf::VertexArray,int>> checkPath(std::array<std::array<int, 5>, 5>) = 0;
};

