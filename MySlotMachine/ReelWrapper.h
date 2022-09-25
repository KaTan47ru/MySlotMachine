#pragma once
#include "Reel.h"
class ReelWrapper:public sf::Drawable
{

public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	ReelWrapper(int reelsCount, sf::Vector2i windowSize);
	void dropTimer();
	void spin();
	void update();
private:
	std::vector<Reel> m_reels;
	sf::Clock* m_clock;
	
};

