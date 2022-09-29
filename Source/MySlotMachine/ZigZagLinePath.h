#pragma once
#include "Path.h"
#include <iostream>
class ZigZagLinePath :
    public Path
{
public:
    virtual std::vector<std::pair<sf::VertexArray, int>> checkPath(std::array<std::array<int, 5>, 5>) ;
};

