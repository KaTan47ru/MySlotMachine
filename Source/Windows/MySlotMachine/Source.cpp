#include <iostream>
#include <SFML/Graphics.hpp>
#include "ReelWrapper.h"
#include "Button.h"
#include "Symbol.h"
#include "PureLinePath.h"
#include "ZigZagLinePath.h"
#include "SlotMachine.h"
#include "StaticState.h"
#include "SpiningState.h"
#include "PrizeState.h"
int main()
{

    srand(time(NULL));
    //Создание окна для рэндера, окно в стиле close, так как не успел прописать flex логику для элементов
    sf::RenderWindow* window= new sf::RenderWindow(sf::VideoMode(1000, 800), "Cruel Gods Spins",sf::Style::Close);
    //Инициализация слот машины, которая в дальнейшем будет управляться состояниями
    SlotMachine * Machine = new SlotMachine;
    //Инициализация состояний
    State* initStane = new StaticState(Machine);
    State* spinState = new SpiningState(Machine);
    State* prizeState = new PrizeState(Machine);
    //Связывание состояний в кольцевой буфер
    initStane->setNextState(spinState);
    spinState->setNextState(prizeState);
    prizeState->setNextState(initStane);
    //Запуск программы. А именно перевод машины в первое состояние
    initStane->runRoutine(window);
    delete initStane;
    delete spinState;
    delete prizeState;
    delete Machine;
    delete window;
    return 0;
}