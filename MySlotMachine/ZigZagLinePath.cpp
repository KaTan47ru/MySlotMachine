#include "ZigZagLinePath.h"

std::vector<std::pair<sf::VertexArray, int>> ZigZagLinePath::checkPath(std::array<std::array<int, 5>, 5> reelData)
{
    std::vector<std::pair<sf::VertexArray, int>> result = {};
    std::array<int, 5> firstLine = { 0,4,0,4,0 };
    std::array<int, 5> secondLine = { 4,0,4,0,4 };
    int combin = 0;
    for (auto& combination : { firstLine,secondLine })
    {
        combin++;
        int symbolCnt = 1;
        int lineSymbol = reelData.at(0).at(combination.at(0));
        for (int reelIdx = 1; reelIdx < 5; reelIdx++)
        {
            if (reelData.at(reelIdx).at(combination.at(reelIdx)) == lineSymbol)
                symbolCnt += 1;
            else
                break;
        }
        if (symbolCnt < 3)
            continue;
        else
        {
            sf::VertexArray lines(sf::LineStrip, 5);
            for (int i = 0; i < 5; i++)
            {
                lines[i].position = sf::Vector2f(200 * i + 100, (combination.at(i) + 1) * 100 + 50);
                lines[i].color = sf::Color::Cyan;
            }
            int prize = symbolCnt * (lineSymbol+1);
            result.push_back({ lines,prize });
            }
    }

    return result;
}
