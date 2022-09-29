#include "PureLinePath.h"

std::vector<std::pair<sf::VertexArray, int>> PureLinePath::checkPath(std::array<std::array<int, 5>, 5> reelData)
{
    std::vector<std::pair<sf::VertexArray, int>> result = {};
	for (int line = 0; line < 5; line++)
	{
        int symbolCnt = 1;
        int lineSymbol = reelData.at(0).at(line);
        for (int reel = 1; reel < 5; reel++)
        {
            if (reelData.at(reel).at(line) == lineSymbol)
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
                lines[i].position = sf::Vector2f(200 * i + 100,(line + 1) * 100+50 );
                lines[i].color = sf::Color::Cyan;
            }
            int prize = symbolCnt * (lineSymbol+1);
            result.push_back({ lines,prize });

        }
       
	}
    return result;
}
