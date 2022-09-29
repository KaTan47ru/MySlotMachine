#include "PrizeState.h"
//  онструктор. «анул€ем указатель на следующее состо€ние, инициализирует указатель на слот машину
PrizeState::PrizeState(SlotMachine* sm)
{
	this->slotMachineHandler = sm;
	this->nextState = nullptr;
}
// ѕереопределенный метод интерфейса, который описывакет жизненный цикл состо€ни€ 
void PrizeState::runRoutine(sf::RenderWindow* window)
{
    // ќтрисовка статичных свойственных этому состо€нию элементов.
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
                    // переход к следующему состо€нию при нажатии кнопки старт
                    this->nextState->runRoutine(window);

                }
            }
        }

        this->slotMachineHandler->render(window);
    }
}
// ћетод дл€ определени€ следующего состо€ни€
void PrizeState::setNextState(State* next)
{
    this->nextState = next;
}
