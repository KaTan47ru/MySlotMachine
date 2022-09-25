#include "ReelWrapper.h"

ReelWrapper::ReelWrapper(int reelsCount, sf::Vector2i windowSize)
{
    
    this->m_clock = new sf::Clock();
    int reelWidth = windowSize.x / 5;
    for (int i = 0; i < 5; i++)
    {
        float x = (i * reelWidth + reelWidth / 2);
        float y = 0.0;
        sf::Vector2f basePosition({ x,y });
        this->m_reels.push_back(Reel(*this->m_clock,100, basePosition));
    }


}
void ReelWrapper::spin()
{
    for (auto& i : this->m_reels)
    {
        float timeToSpin =10+ rand() % 20;
        i.spin(timeToSpin);
    }
}
void ReelWrapper::dropTimer() 
{
    this->m_clock->restart();
}


void ReelWrapper::update() 
{
    auto time = this->m_clock->restart().asSeconds();
    for (auto& i : this->m_reels)
    {
        i.update(time);
    }
}


void ReelWrapper::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& i : this->m_reels)
    {
        target.draw(i,states);
    }
}


