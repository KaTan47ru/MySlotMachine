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
	void processPrize();
	void stop();
	int getPrizeValue() const;
	bool update();
	~ReelWrapper();
private:
	int reelsStopedFlag;
	std::vector<std::pair<sf::VertexArray, int>> prizes;
	std::vector<Path*> winingWays;
	std::vector<Reel*> drumbReels;
	sf::Clock* pClock;
	
};

