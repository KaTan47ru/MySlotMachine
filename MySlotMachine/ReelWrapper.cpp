#include "ReelWrapper.h"

ReelWrapper::ReelWrapper(int reelsCount, sf::Vector2i windowSize)
{
    this->isSpin = false;
    this->evaluatedDebugFlag = 0;
    this->m_clock = new sf::Clock();
    this->spinTime = 0;
    int reelWidth = windowSize.x / 5;
    this->m_paths.push_back(new PureLinePath);
    this->m_paths.push_back(new ZigZagLinePath);
    for (int i = 0; i < 5; i++)
    {
        float x = (i * reelWidth + reelWidth / 2);
        float y = 0.0;
        sf::Vector2f basePosition({ x,y });
        this->m_reels.push_back(Reel(*this->m_clock,100, basePosition,true));
    }


}
void ReelWrapper::spin()
{
    this->evaluatedDebugFlag = 1;
    this->isSpin = true;
    for (auto& i : this->m_reels)
    {
        float timeToSpin =10+ rand() % 20;
        i.spin(timeToSpin);
    }
}
void ReelWrapper::restart()
{
    this->m_clock->restart();
    this->prizes.clear();
}


bool ReelWrapper::update() 
{
    auto time = this->m_clock->restart().asSeconds();
    bool reelsStoped = true;
    int reelStatus = 0;
    for (auto& i : this->m_reels)
    {
        reelsStoped &= i.updateNew(time);
        reelStatus += i.getStatus();
    }
    
    if (reelStatus == 5 && this->evaluatedDebugFlag ==1)
    {
        this->processPrize();
        this->evaluatedDebugFlag = 0;
    }
    return reelsStoped;
}

void ReelWrapper::processPrize() 
{
    
    std::array<std::array<int, 5>, 5> reelsObjects;
    for (int i = 0; i < 5; i++)
    {
        reelsObjects.at(i) = this->m_reels.at(i).getSymbolsNew();
    }
    
    for (auto& path : m_paths)
    {
        for (auto& i : path->checkPath(reelsObjects))
        {
            this->prizes.push_back(i);
        }
    }
}

void ReelWrapper::stop()
{
    this->evaluatedDebugFlag = 1;
    for (auto& i : this->m_reels)
    {
        i.stop();
    }
}

int ReelWrapper::getPrizeValue() const
{
    if (this->prizes.size() == 0)
    {
        return 0;
   }
    else
    {
        int res = 0;
        for (auto& i : this->prizes)
        {
            res += i.second;
        }
        return res;
    }
}




void ReelWrapper::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& i : this->m_reels)
    {
        target.draw(i,states);
    }
    if (this->prizes.size() != 0)
    {
        for (auto& i : this->prizes)
        {
            target.draw(i.first, states);
        }

    }
}


