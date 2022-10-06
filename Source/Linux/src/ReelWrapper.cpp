#include "ReelWrapper.h"

ReelWrapper::ReelWrapper(const int& reelsCount,const  sf::Vector2i & windowSize)
{

    this->reelsStopedFlag = 0;
    this->pClock = new sf::Clock();

    int reelWidth = windowSize.x / 5;
    this->winingWays.push_back(new PureLinePath);
    this->winingWays.push_back(new ZigZagLinePath);
    for (int i = 0; i < 5; i++)
    {
        float x = (i * reelWidth + reelWidth / 2);
        float y = 0.0;
        sf::Vector2f basePosition({ x,y });
        this->drumbReels.push_back(new Reel(100, basePosition,true));
    }


}
void ReelWrapper::spin()
{
    this->reelsStopedFlag = 1;
    for (auto& i : this->drumbReels)
    {
        float timeToSpin =10+ rand() % 20;
        i->spin(timeToSpin);
    }
}
void ReelWrapper::restart()
{
    this->pClock->restart();
    this->prizes.clear();
}


bool ReelWrapper::update() 
{
    auto time = this->pClock->restart().asSeconds();
    bool reelsStoped = true;
    int reelStatus = 0;
    for (auto& i : this->drumbReels)
    {
        reelsStoped &= i->updateNew(time);
        reelStatus += i->getStatus();
    }
    
    if (reelStatus == 5 && this->reelsStopedFlag ==1)
    {
        this->processPrize();
        this->reelsStopedFlag = 0;
    }
    return reelsStoped;
}

void ReelWrapper::processPrize() 
{
    
    std::array<std::array<int, 5>, 5> reelsObjects;
    for (int i = 0; i < 5; i++)
    {
        reelsObjects.at(i) = this->drumbReels.at(i)->getSymbolsNew();
    }
    
    for (auto& path : winingWays)
    {
        for (auto& i : path->checkPath(reelsObjects))
        {
            this->prizes.push_back(i);
        }
    }
}

void ReelWrapper::stop()
{
    this->reelsStopedFlag = 1;
    for (auto& i : this->drumbReels)
    {
        i->stop();
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

ReelWrapper::~ReelWrapper()
{
    for (auto& reel : this->drumbReels)
    {
        delete reel;
    }
    for (auto& path : this->winingWays)
    {
        delete path;
    }
    delete this->pClock;
}




void ReelWrapper::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& i : this->drumbReels)
    {
        target.draw(*i,states);
    }
    if (this->prizes.size() != 0)
    {
        for (auto& i : this->prizes)
        {
            target.draw(i.first, states);
        }

    }
}


