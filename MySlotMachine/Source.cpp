#include <iostream>
#include <SFML/Graphics.hpp>
#include "ReelWrapper.h"
int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::CircleShape shape(100.f);

    sf::Text textTitle;
    sf::Font titleFont;
    titleFont.loadFromFile("assets/font.ttf");
    textTitle.setString("Cruel Gods Spins");
    textTitle.setFillColor(sf::Color::Color(0,0,0));
    textTitle.setFont(titleFont);
    textTitle.setPosition({ 300,10 });
    textTitle.setCharacterSize(50);

    sf::Texture* steelTexture = new sf::Texture;
    steelTexture->loadFromFile("assets/scarfold.jpg");
    sf::RectangleShape topBack;
    topBack.setSize({ 1000,100 });
    topBack.setOutlineColor(sf::Color::White);
    topBack.setPosition(0, 0);
    topBack.setTexture(steelTexture);

    sf::Texture* paperTexture = new sf::Texture;
    paperTexture->loadFromFile("assets/paper.png");
    sf::RectangleShape topFront;
    topFront.setSize({ 1000,100 });
    topFront.setOutlineColor(sf::Color::White);
    topFront.setPosition(0, 0);
    topFront.setTexture(paperTexture);


    sf::Texture* botTexture = new sf::Texture;
    botTexture->loadFromFile("assets/scarfold.jpg");
    sf::RectangleShape bot;
    bot.setSize({ 1000,200 });
    bot.setOutlineColor(sf::Color::White);
    bot.setPosition(0, 600);
    bot.setTexture(botTexture);

    sf::Texture* wireTexture = new sf::Texture;
    wireTexture->loadFromFile("assets/wires.jpg");
    sf::RectangleShape left;
    left.setSize({ 10,800 });
    left.setOutlineColor(sf::Color::White);
    left.setPosition(0, 0);
    left.setTexture(wireTexture);

    sf::RectangleShape right;
    right.setSize({ 10,800 });
    right.setOutlineColor(sf::Color::White);
    right.setPosition(990, 0);
    right.setTexture(wireTexture);

    shape.setFillColor(sf::Color::Green);
    sf::Texture texture;
    if (!texture.loadFromFile("assets/insingnia.png"))
        return -1;
    // Assign it to a sprite
    sf::Sprite sprite;
    //sprite.setTexture(texture);
    // Draw the textured sprite
    ReelWrapper reels(5, { 1000,800 });
    bool spin = true;
    std::vector<sf::RectangleShape*> mesh;
    for (int i = 0; i < 1000; i += 100)
    {
        sf::RectangleShape* line = new sf::RectangleShape;
        line->setSize({ 1,800 });
        line->setFillColor(sf::Color::Green);
        line->setPosition(i, 0);
        mesh.push_back(line);
    }
    for (int j = 0; j < 800; j += 100)
    {
        sf::RectangleShape *line = new sf::RectangleShape;
        line->setSize({ 1000,1 });
        line->setFillColor(sf::Color::Green);
        line->setPosition(0, j);
        mesh.push_back(line);
    }
    sf::Texture* a = new sf::Texture;
    a->loadFromFile("assets/marker.png");
   
    std::vector<sf::ConvexShape> markers;
    for (int i = 0; i < 5; i++)
    {
        sf::ConvexShape polygon;
        polygon.setPointCount(3);
        polygon.setPoint(0, sf::Vector2f(0, 100 + 100 * i));
        polygon.setPoint(1, sf::Vector2f(0, 200 + 100 * i));
        polygon.setPoint(2, sf::Vector2f(50, 150 + 100 * i));
       
       // polygon.setFillColor(sf::Color::Red);
        polygon.setTexture(a);
        markers.push_back(polygon);
    }

    
    sf::Sprite startButton;
    sf::Texture *buttonTexture = new sf::Texture;
    buttonTexture->loadFromFile("assets/button.png");
    startButton.setTexture(*buttonTexture);
    startButton.setOrigin(buttonTexture->getSize().x / 2, buttonTexture->getSize().y / 2);
    startButton.setPosition(400, 700);
    sf::Text startText;
    titleFont.loadFromFile("assets/font.ttf");
    startText.setString("start");
    startText.setFillColor(sf::Color::Color(255, 0, 0));
    startText.setFont(titleFont);
    startText.setCharacterSize(35);
    startText.setOrigin({ 87.5,17.5 });
    startText.setPosition({ 400,700 });
    auto transform = startButton.getTransform().getMatrix();
    for (int i = 0; i < 16; i++)
    {
        std::cout << transform[i]<<" ";
    }
    sf::Sprite stopButton;

    while (window.isOpen())
    {
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                reels.spin();
            }
        }


       /* auto deltaTime = clock.restart().asSeconds();
        auto position = sprite.getPosition();
        constexpr float speed = 100.f;
        position.y += deltaTime*speed;
        if (position.y > 600)
        {
            position.y -= 600;
        }
        sprite.setPosition(position);*/
        if (spin == true)
        {
           
          reels.update();
            
        }
        
        window.clear();
        window.draw(reels);
        window.draw(left);
        window.draw(right);
        window.draw(topBack);
        window.draw(topFront);
        window.draw(bot);
        for (auto& i : markers)
        {
            window.draw(i);
        }
        for (auto& i : mesh)
        {
       //    window.draw(*i);
        }

        window.draw(textTitle);
        window.draw(startButton);
        window.draw(startText);
        window.display();
    }

    return 0;
}