#include "Reel.h"



Symbol* Reel::getNewSymbol(sf::Vector2f basePosition)
{
    std::vector<std::string > pngs = { "flag.png","insingnia.png","sla.png","imp.png" };
    int fileIdx = rand() % 100;
    if (fileIdx > 90)
    {
        fileIdx = 3;
    }
    else if (fileIdx <= 90 && fileIdx > 70)
    {
        fileIdx = 2;
    }
    else if (fileIdx > 40)
    {
        fileIdx = 1;
    }
    else
    {
        fileIdx = 0;

    }

    std::string fileName = "assets/" + pngs.at(fileIdx);
    Symbol * result = new Symbol(fileName,basePosition,fileIdx);

    return result;
}



int Reel::getStatus()
{
    if (this->isSpining == false)
        return 1;
    else
        return -1;
}

Reel::Reel(sf::Clock& clock, float speed, sf::Vector2f basePosition = { 0.0,0.0 },bool standart =true)
{
    this->isSpining = false;
    this->acceleration = 1;
    this->timeToSpin.first = 0;
    this->timeToSpin.second = 0;
    this->speed = 0;
    this->basePosition = basePosition;
    for (int i = 0; i < 7; i++)
    {
        float y = (50.0 + 100.0 * i);
        Symbol* newSymb = Reel::getNewSymbol({ basePosition.x, y });
        this->m_symbs.push_back(newSymb);
    }
}

void Reel::stop()
{
    this->timeToSpin.first = 0;

}

std::array<int, 5> Reel::getSymbolsNew() const
{
    std::array<int, 5> result;
    auto it = this->m_symbs.begin();
    it++;
    for (size_t i = 0; i < 5; i++)
    {
        result.at(i) = (* it)->getIndex();
        it++;
    }
    return result;
}
void Reel::spin(float timeToSpin)
{
    this->isSpining = true;
    this->timeToSpin.first = timeToSpin/2;
    this->timeToSpin.second = timeToSpin/2;
    this->speed = 100;
}

bool Reel::updateNew(float time)
{
    Symbol* newObject = nullptr;
    if (this->timeToSpin.first > 0)
    {
        
        if (this->acceleration < 10)
            this->acceleration += 0.01;
        for (auto symbIter : this->m_symbs)
        {
            auto position = symbIter->getPosition();
            position.y += 0.001 * this->acceleration * this->speed;

            timeToSpin.first -= time;

            if (position.y >= 700)
            {
                newObject = Reel::getNewSymbol(this->basePosition);
            }
            else
            {
                symbIter->setPosition(position);
            }
        }
        if (newObject != nullptr)
        {
            delete this->m_symbs.back();
            this->m_symbs.pop_back();
            this->m_symbs.push_front(newObject);
        }
        return false;
        
    }
    auto yPos = this->m_symbs.back()->getPosition().y + 50;
    if (this->timeToSpin.second > 0 || (int)yPos != 700)
    {
        if (this->acceleration > 1)
            this->acceleration -= 0.01;
        for (auto symbIter : this->m_symbs)
        {
            auto position = symbIter->getPosition();
            position.y += 0.001 * this->acceleration * this->speed;

            timeToSpin.second -= time;

            if (position.y >= 700)
            {
                newObject = Reel::getNewSymbol(this->basePosition);
            }
            else
            {
                symbIter->setPosition(position);
            }
        }
        if (newObject != nullptr)
        {
            delete this->m_symbs.back();
            this->m_symbs.pop_back();
            this->m_symbs.push_front(newObject);
        }
        return false;
    }
    this->isSpining = false;
    return true;
}



void Reel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{


    for (auto& i : m_symbs)
    {
        target.draw(*i, states);
    }
}
