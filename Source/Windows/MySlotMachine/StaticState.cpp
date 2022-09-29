#include "StaticState.h"

// Конструктор. Зануляем указатель на следующее состояние, инициализирует указатель на слот машину
StaticState::StaticState(SlotMachine* pSlotMachine)
{
	this->slotMachineHandler = pSlotMachine;
    this->nextState = nullptr;
}

// Переопределенный метод интерфейса, который описывакет жизненный цикл состояния 
void StaticState::runRoutine(sf::RenderWindow* window)
{
    // Метод приводящий слот машину в начальное(первое) состояние
    this->slotMachineHandler->dropMachine();
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
                    // если пользователь нажал кнопку старт происходит переход к следующему состоянию.
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
