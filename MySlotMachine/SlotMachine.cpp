#include "SlotMachine.h"

SlotMachine::SlotMachine()
{
    this->drawMesh = true;
    srand(time(NULL));


    
    this->textFont = new  sf::Font;
    textFont->loadFromFile("assets/font.ttf");

    

    sf::Texture* steelTexture = new sf::Texture;
    steelTexture->loadFromFile("assets/scarfold.jpg");
    
    sf::RectangleShape *topBack = new sf::RectangleShape;
    topBack->setSize({ 1000,100 });
    topBack->setOutlineColor(sf::Color::White);
    topBack->setPosition(0, 0);
    topBack->setTexture(steelTexture);
    this->m_static.push_back(topBack);

    sf::Texture* paperTexture = new sf::Texture;
    paperTexture->loadFromFile("assets/paper.png");

    sf::RectangleShape * topFront = new sf::RectangleShape;
    topFront->setSize({ 1000,100 });
    topFront->setOutlineColor(sf::Color::White);
    topFront->setPosition(0, 0);
    topFront->setTexture(paperTexture);
    this->m_static.push_back(topFront);

    sf::Texture* botTexture = new sf::Texture;
    botTexture->loadFromFile("assets/scarfold.jpg");

    sf::RectangleShape *bot = new sf::RectangleShape;
    bot->setSize({ 1000,200 });
    bot->setOutlineColor(sf::Color::White);
    bot->setPosition(0, 600);
    bot->setTexture(botTexture);
    this->m_static.push_back(bot);

    sf::Texture* wireTexture = new sf::Texture;
    wireTexture->loadFromFile("assets/wires.jpg");

    sf::RectangleShape *left = new sf::RectangleShape;
    left->setSize({ 10,800 });
    left->setOutlineColor(sf::Color::White);
    left->setPosition(0, 0);
    left->setTexture(wireTexture);
    this->m_static.push_back(left);

    sf::RectangleShape* right = new sf::RectangleShape;;
    right->setSize({ 10,800 });
    right->setOutlineColor(sf::Color::White);
    right->setPosition(990, 0);
    right->setTexture(wireTexture);
    this->m_static.push_back(right);

    sf::Texture* markerTexture = new sf::Texture;
    markerTexture->loadFromFile("assets/marker.png");

    std::vector<sf::ConvexShape> markers;
    for (int i = 0; i < 5; i++)
    {
        sf::ConvexShape *polygon = new sf::ConvexShape;
        polygon->setPointCount(3);
        polygon->setPoint(0, sf::Vector2f(0, 100 + 100 * i));
        polygon->setPoint(1, sf::Vector2f(0, 200 + 100 * i));
        polygon->setPoint(2, sf::Vector2f(50, 150 + 100 * i));
        polygon->setTexture(markerTexture);
        this->m_static.push_back(polygon);
    }




    for (int i = 0; i < 1000; i += 100)
    {
        sf::RectangleShape* line = new sf::RectangleShape;
        line->setSize({ 1,800 });
        line->setFillColor(sf::Color::Green);
        line->setPosition(i, 0);
        this->mesh.push_back(line);
    }
    for (int j = 0; j < 800; j += 100)
    {
        sf::RectangleShape* line = new sf::RectangleShape;
        line->setSize({ 1000,1 });
        line->setFillColor(sf::Color::Green);
        line->setPosition(0, j);
        this->mesh.push_back(line);
    }

    sf::Text* prizeText = new sf::Text;
    prizeText->setString("Prize:");
    prizeText->setFillColor(sf::Color::Color(0, 0, 0));
    prizeText->setFont(*textFont);
    prizeText->setPosition({ 50,650 });
    prizeText->setCharacterSize(50);
    this->m_static.push_back(prizeText);

    this->helpText = new sf::Text;
    this->helpText->setString("Press 'Start' to Spin");
    this->helpText->setFillColor(sf::Color::Color(0, 0, 0));
    this->helpText->setFont(*textFont);
    this->helpText->setCharacterSize(50);
    auto h =this->helpText->getLocalBounds().height;
    auto w = this->helpText->getLocalBounds().width;
    this->helpText->setOrigin(w/2,h/2);
    this->helpText->setPosition({ 500,25 });

    this->prizeValue = new sf::Text;
    this->prizeValue->setString("0$");
    this->prizeValue->setFillColor(sf::Color::Color(0, 0, 0));
    this->prizeValue->setFont(*textFont);
    this->prizeValue->setPosition({ 50,700 });
    this->prizeValue->setCharacterSize(50);

    this->startButton = new Button({ 400,700 }, "Start");
    this->stopButton = new Button({ 600,700 }, "Stop");

    this->m_reels = new ReelWrapper(5, { 1000,800 });

}

void SlotMachine::processPrize()
{
    this->helpText->setString("Press 'Start' to play again");
    auto h = this->helpText->getLocalBounds().height;
    auto w = this->helpText->getLocalBounds().width;
    this->helpText->setOrigin(w / 2, h / 2);
    this->helpText->setPosition({ 500,25 });
    auto prize = this->m_reels->getPrizeValue();
    this->prizeValue->setString(std::to_string(prize)+"$");
}

void SlotMachine::dropMachine()
{
    this->helpText->setString("Press 'Start' to Spin");
    auto h = this->helpText->getLocalBounds().height;
    auto w = this->helpText->getLocalBounds().width;
    this->helpText->setOrigin(w / 2, h / 2);
    this->helpText->setPosition({ 500,25 });
    this->prizeValue->setString("0$");
    this->m_reels->restart();
}




void SlotMachine::spin()
{
    this->helpText->setString("Wait for spining ...");
    auto h = this->helpText->getLocalBounds().height;
    auto w = this->helpText->getLocalBounds().width;
    this->helpText->setOrigin(w / 2, h / 2);
    this->helpText->setPosition({ 500,25 });
    this->m_reels->spin();
}

bool SlotMachine::render(sf::RenderWindow* window)
{
    bool result = false;
    window->clear();
    result = this->m_reels->update();
    window->draw(*this->m_reels);
    for (auto& object : this->m_static)
    {

        window->draw(*object);
    }
    window->draw(*this->startButton);
    window->draw(*this->stopButton);
    window->draw(*this->prizeValue);
    window->draw(*this->helpText);
    if (this->drawMesh == true)
    {
        for (auto& i : this->mesh)
        {
            window->draw(*i);
        }
    }
    window->display();
    return result;
}

void SlotMachine::stop()
{
    this->m_reels->stop();
}


bool SlotMachine::trackStartClicks(sf::Vector2i mousePosition)
{
    return this->startButton->checkMousePressed(mousePosition);
}

SlotMachine::~SlotMachine()
{
    for (auto& object : this->m_static)
    {
        delete object;
    }
}

bool SlotMachine::trackStopClicks(sf::Vector2i mousePosition)
{
    return this->stopButton->checkMousePressed(mousePosition);

}

void SlotMachine::trackMouse(sf::Vector2i mousePosition)
{
    this->startButton->checkMouse(mousePosition);
    this->stopButton->checkMouse(mousePosition);
}
