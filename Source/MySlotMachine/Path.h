#pragma once
#include <array>
#include <vector>
#include <SFML/Graphics.hpp>
// Интерфейс для путей разного вида. Планировал реализовать побольше путей, о в итоге взял две самые простые комбинации.
class Path
{
public:

	virtual std::vector<std::pair<sf::VertexArray,int>> checkPath(std::array<std::array<int, 5>, 5>) = 0;
};

