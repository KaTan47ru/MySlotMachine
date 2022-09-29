#pragma once
#include "Reel.h"
#include "PureLinePath.h"
#include "ZigZagLinePath.h"
class ReelWrapper:public sf::Drawable
{

public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	ReelWrapper(int reelsCount, sf::Vector2i windowSize);
	void restart();
	void spin();
	bool update();
	void processPrize();
	void stop();
	int getPrizeValue() const;
private:
	int evaluatedDebugFlag;
	bool isSpin;
	float spinTime;
	std::vector<std::pair<sf::VertexArray, int>> prizes;
	std::vector<Path*> m_paths;
	std::vector<Reel> m_reels;
	sf::Clock* m_clock;
	
};

