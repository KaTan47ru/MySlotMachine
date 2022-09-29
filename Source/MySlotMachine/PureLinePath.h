#pragma once
#include "Path.h"
#include <iostream>
// реализация интерфейса для "прямых" путей:
// - - - - -
// a b c d f
// a d f g h
// l s h l p
// a p o k p
//
class PureLinePath :
    public Path
{

public:
    virtual std::vector<std::pair<sf::VertexArray, int>> checkPath(std::array<std::array<int, 5>, 5>) ;
};

