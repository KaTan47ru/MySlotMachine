#pragma once
#include "Path.h"
#include <iostream>
// ���������� ���������� ��� "���-�������" �����:
// - � - k -
// a b c d f
// a d f g h
// l s h l p
// a - o - p
//
class ZigZagLinePath :
    public Path
{
public:
    virtual std::vector<std::pair<sf::VertexArray, int>> checkPath(std::array<std::array<int, 5>, 5>) ;
};

