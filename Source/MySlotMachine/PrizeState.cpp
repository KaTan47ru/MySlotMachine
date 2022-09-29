#include "PrizeState.h"

PrizeState::PrizeState(SlotMachine* sm)
{
	this->slotMachineHandler = sm;
	this->nextState = nullptr;
}

void PrizeState::runRoutine(sf::RenderWindow* window)
{
    this->slotMachineHandler->processPrize();
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
                if (this->slotMachineHandler->trackStartClicks(sf::Mouse::getPosition(*window)) == true)
                {
                    this->nextState->runRoutine(window);

                }
            }
        }

        this->slotMachineHandler->render(window);
    }
}

void PrizeState::setNextState(State* next)
{
    this->nextState = next;
}
