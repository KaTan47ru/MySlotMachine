#include "Reel.h"

std::pair<sf::Sprite,sf::Texture*> Reel::getNextSymbol(sf::Vector2f basePosition)
{
    std::vector<std::string > pngs = {"flag.png","insingnia.png","sla.png","imp.png"};
    int fileIdx = rand() % 100;
    if (fileIdx > 90)
    {
        fileIdx = 3;
    }
    else if(fileIdx<=90&&fileIdx>70)
    {
        fileIdx = 2;
    }
    else if (fileIdx>40)
    {
        fileIdx = 1;
    }
    else
    {
        fileIdx = 0;

    }

    std::string fileName = "assets/" + pngs.at(fileIdx);
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile(fileName);
    sf::Sprite sprite;
    
    auto size = texture->getSize();
    
    sprite.setOrigin(size.x / 2, size.y / 2);
    sprite.setTexture(*texture);
    sprite.move(basePosition.x,basePosition.y+texture->getSize().y/2);
    
    return {sprite,texture};
}



Reel::Reel(sf::Clock& clock, float speed, sf::Vector2f basePosition = { 0.0,0.0 })
{
    this->timeToSpin = 0;
    this->speed = speed;
    this->basePosition = basePosition;
    for (int i = 0; i < 7; i++)
    {
        sf::Texture* tmpTexture = new sf::Texture;
        sf::Sprite tmpSprite;

        if (tmpTexture->loadFromFile("assets/flag.png"))
        {   
            auto size = tmpTexture->getSize();
            tmpSprite.setOrigin(size.x / 2, size.y / 2);
            tmpSprite.setTexture(*tmpTexture);
            tmpSprite.move(basePosition.x, 100*i+ size.y / 2);
            this->reelObjects.push_back({ tmpSprite,tmpTexture });
        }

    }
}
void Reel::spin(float timeToSpin)
{
    this->timeToSpin = timeToSpin;
}
void Reel::update(float time)
{
    if(this->timeToSpin>0||this->anchor!=0)
    for (int i = 0; i < this->reelObjects.size(); i++)
    {
        this->anchor = (this->anchor + 1) % 100;
        auto position = reelObjects.at(i).first.getPosition();

        position.y += 0.01 * this->speed;
       // std::cout << time <<std::endl;
        timeToSpin -= time;
        if (position.y > 700+ reelObjects.at(i).second->getSize().y/2)
        {
            auto newObject = Reel::getNextSymbol(basePosition);
            delete this->reelObjects.at(i).second;
            this->reelObjects.at(i) = newObject;
        }
        else
        {
            reelObjects.at(i).first.setPosition(position);

        }
    }
}

void Reel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    for(auto&i:reelObjects)
	    target.draw(i.first, states);
}
