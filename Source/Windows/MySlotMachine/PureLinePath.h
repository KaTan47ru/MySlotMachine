#pragma once
#include "Path.h"
#include <iostream>
// ���������� ���������� ��� "������" �����:
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
    virtual std::vector<std::pair<sf::VertexArray, int>> checkPath(const std::array<std::array<int, 5>, 5 > &) const;
};

