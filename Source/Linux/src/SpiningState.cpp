#include "SpiningState.h"
//  онструктор. «анул€ем указатель на следующее состо€ние, инициализирует указатель на слот машину
SpiningState::SpiningState(SlotMachine* sm)
{
	this->slotMachineHandler = sm;
	this->nextState = nullptr;
}
// ѕереопределенный метод интерфейса, который описывакет жизненный цикл состо€ни€ 
void SpiningState::runRoutine(sf::RenderWindow* window)
{
    // ¬џзов метода запускающего вращение барабанов
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
                    // »нициирование остановки барабана при нажатой кнопке стоп
                    this->slotMachineHandler->stop();

                }
            }
        }
        // —мотритс€, остановлоись ли бабаны, если да, то происходит перезод в третье состо€ние.
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
