#include "SpiningState.h"

SpiningState::SpiningState(SlotMachine* sm)
{
	this->slotMachineHandler = sm;
	this->nextState = nullptr;
}

void SpiningState::runRoutine(sf::RenderWindow* window)
{
    this->slotMachineHandler->spin();
    while (window->isOpen())
    {


        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::MouseMoved)
            {
                auto cursorPos = sf::Mouse::getPosition(*window);
                this->slotMachineHandler->trackMouse(cursorPos);

            }
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (this->slotMachineHandler->trackStopClicks(sf::Mouse::getPosition(*window)) == true)
                {
                    this->slotMachineHandler->stop();

                }
            }
        }

        if(this->slotMachineHandler->render(window)==true)
        {
            
            this->nextState->runRoutine(window);
        }
    }
}

void SpiningState::setNextState(State*next)
{
	this->nextState = next;
}
