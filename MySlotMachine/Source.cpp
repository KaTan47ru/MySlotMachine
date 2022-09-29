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
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Cruel Gods Spins");
    SlotMachine * Machine = new SlotMachine;
    State* initStane = new StaticState(Machine);
    State* spinState = new SpiningState(Machine);
    State* prizeState = new PrizeState(Machine);
    
    initStane->setNextState(spinState);
    spinState->setNextState(prizeState);
    prizeState->setNextState(initStane);

    initStane->runRoutine(&window);
    return 0;
}