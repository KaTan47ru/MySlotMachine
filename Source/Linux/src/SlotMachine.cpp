#include "SlotMachine.h"
// ����������. ���������� ����������� ���������, ���������������� ��������
SlotMachine::SlotMachine()
{

    srand(time(NULL));


    
    this->textFont = new  sf::Font;
    textFont->loadFromFile("assets/font.ttf");

    

    sf::Texture* steelTexture = new sf::Texture;
    steelTexture->loadFromFile("assets/scarfold.jpg");
    this->textures.push_back(steelTexture);
    
    sf::RectangleShape *topBack = new sf::RectangleShape;
    topBack->setSize({ 1000,100 });
    topBack->setOutlineColor(sf::Color::White);
    topBack->setPosition(0, 0);
    topBack->setTexture(steelTexture);
    this->staticDrawables.push_back(topBack);

    sf::Texture* paperTexture = new sf::Texture;
    paperTexture->loadFromFile("assets/paper.png");
    this->textures.push_back(paperTexture);

    sf::RectangleShape * topFront = new sf::RectangleShape;
    topFront->setSize({ 1000,100 });
    topFront->setOutlineColor(sf::Color::White);
    topFront->setPosition(0, 0);
    topFront->setTexture(paperTexture);
    this->staticDrawables.push_back(topFront);

    sf::Texture* botTexture = new sf::Texture;
    botTexture->loadFromFile("assets/scarfold.jpg");
    this->textures.push_back(botTexture);

    sf::RectangleShape *bot = new sf::RectangleShape;
    bot->setSize({ 1000,200 });
    bot->setOutlineColor(sf::Color::White);
    bot->setPosition(0, 600);
    bot->setTexture(botTexture);
    this->staticDrawables.push_back(bot);

    sf::Texture* wireTexture = new sf::Texture;
    wireTexture->loadFromFile("assets/wires.jpg");
    this->textures.push_back(wireTexture);

    sf::RectangleShape *left = new sf::RectangleShape;
    left->setSize({ 10,800 });
    left->setOutlineColor(sf::Color::White);
    left->setPosition(0, 0);
    left->setTexture(wireTexture);
    this->staticDrawables.push_back(left);

    sf::RectangleShape* right = new sf::RectangleShape;;
    right->setSize({ 10,800 });
    right->setOutlineColor(sf::Color::White);
    right->setPosition(990, 0);
    right->setTexture(wireTexture);
    this->staticDrawables.push_back(right);

    sf::Texture* markerTexture = new sf::Texture;
    markerTexture->loadFromFile("assets/marker.png");
    this->textures.push_back(markerTexture);

    std::vector<sf::ConvexShape> markers;
    for (int i = 0; i < 5; i++)
    {
        sf::ConvexShape *polygon = new sf::ConvexShape;
        polygon->setPointCount(3);
        polygon->setPoint(0, sf::Vector2f(0, 100 + 100 * i));
        polygon->setPoint(1, sf::Vector2f(0, 200 + 100 * i));
        polygon->setPoint(2, sf::Vector2f(50, 150 + 100 * i));
        polygon->setTexture(markerTexture);
        this->staticDrawables.push_back(polygon);
    }




    
    sf::Text* prizeText = new sf::Text;
    prizeText->setString("Prize:");
    prizeText->setFillColor(sf::Color::Black);
    prizeText->setFont(*textFont);
    prizeText->setPosition({ 50,650 });
    prizeText->setCharacterSize(50);
    this->staticDrawables.push_back(prizeText);

    this->helpText = new sf::Text;
    this->helpText->setString("Press 'Start' to Spin");
    this->helpText->setFillColor(sf::Color::Black);
    this->helpText->setFont(*textFont);
    this->helpText->setCharacterSize(50);
    auto h =this->helpText->getLocalBounds().height;
    auto w = this->helpText->getLocalBounds().width;
    this->helpText->setOrigin(w/2,h/2);
    this->helpText->setPosition({ 500,25 });

    this->prizeValue = new sf::Text;
    this->prizeValue->setString("0$");
    this->prizeValue->setFillColor(sf::Color::Black);
    this->prizeValue->setFont(*textFont);
    this->prizeValue->setPosition({ 50,700 });
    this->prizeValue->setCharacterSize(50);

    this->startButton = new Button({ 400,700 }, "Start");
    this->stopButton = new Button({ 600,700 }, "Stop");

    this->drumb = new ReelWrapper(5, { 1000,800 });

}
// �������� ��� ����������� ��������� ������ ��������. �������� ���������� ����, ������� �������
void SlotMachine::processPrize()
{
    this->helpText->setString("Press 'Start' to play again");
    auto h = this->helpText->getLocalBounds().height;
    auto w = this->helpText->getLocalBounds().width;
    this->helpText->setOrigin(w / 2, h / 2);
    this->helpText->setPosition({ 500,25 });
    auto prize = this->drumb->getPrizeValue();
    this->prizeValue->setString(std::to_string(prize)+"$");
}
// ��������� ��� ����� ��������� ������ ��� "�������" �� �� ���������
void SlotMachine::dropMachine()
{
    this->helpText->setString("Press 'Start' to Spin");
    auto h = this->helpText->getLocalBounds().height;
    auto w = this->helpText->getLocalBounds().width;
    this->helpText->setOrigin(w / 2, h / 2);
    this->helpText->setPosition({ 500,25 });
    this->prizeValue->setString("0$");
    this->drumb->restart();
}



// ��������� ��� �������� ���������.
void SlotMachine::spin()
{
    this->helpText->setString("Wait for spining ...");
    auto h = this->helpText->getLocalBounds().height;
    auto w = this->helpText->getLocalBounds().width;
    this->helpText->setOrigin(w / 2, h / 2);
    this->helpText->setPosition({ 500,25 });
    this->drumb->spin();
}
// ������ ���� ��������. ���������� true ���� �������� ��������.
// ���� ���������� ��� ���������, ������ ���������� ���������� ������ ������ ��������� ��� �������� � ������
bool SlotMachine::render(sf::RenderWindow* window)
{
    bool result = false;
    window->clear();
    result = this->drumb->update();
    window->draw(*this->drumb);
    for (auto& object : this->staticDrawables)
    {

        window->draw(*object);
    }
    window->draw(*this->startButton);
    window->draw(*this->stopButton);
    window->draw(*this->prizeValue);
    window->draw(*this->helpText);
   
    window->display();
    return result;
}
// ��������� ���� ������. ���������� ������ ��������� � ������ ������� ������ ����
void SlotMachine::stop()
{
    this->drumb->stop();
}

// ������������ ������� ������ �����.
// ����������� 1 � 3 ����������.
bool SlotMachine::trackStartClicks(const sf::Vector2i & mousePosition)
{
    return this->startButton->checkMousePressed(mousePosition);
}

SlotMachine::~SlotMachine()
{
    for (auto& object : this->staticDrawables)
    {
        delete object;
    }
    for (auto& texture : this->textures)
    {
        delete texture;
    }
    delete this->startButton;
    delete this->stopButton;
    delete this->drumb;
    delete this->prizeValue;
    delete this->helpText;
    delete this->textFont;
}
// ������� ������ ����. ������������ ������ ����������
bool SlotMachine::trackStopClicks(const sf::Vector2i & mousePosition)
{
    return this->stopButton->checkMousePressed(mousePosition);

}
// ����������� �������� ����� ��� ������� �������� :hover � ������.
void SlotMachine::trackMouse(const sf::Vector2i & mousePosition)
{
    this->startButton->checkMouse(mousePosition);
    this->stopButton->checkMouse(mousePosition);
}
