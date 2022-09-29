#include "StaticState.h"

StaticState::StaticState(SlotMachine* pSlotMachine)
{
	this->slotMachineHandler = pSlotMachine;
    this->nextState = nullptr;
}

void StaticState::runRoutine(sf::RenderWindow* window)
{
    this->slotMachineHandler->dropMachine();
    while (window->isOpen())
    {


        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::MouseMoved)
            {
                auto cursorPos = sf::Mouse::getPosition(*window);
                //std::cout << cursorPos.x<<" " << cursorPos.y << std::endl;
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

void StaticState::setNextState(State* next)
{
    this->nextState = next;
}
