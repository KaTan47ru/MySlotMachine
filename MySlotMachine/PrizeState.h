#pragma once
#include "State.h"
#include"SlotMachine.h"
class PrizeState :
    public State
{
    SlotMachine* slotMachineHandler;
    State* nextState;
public:
    PrizeState(SlotMachine*);
    virtual void  runRoutine(sf::RenderWindow* window);
    virtual void setNextState(State*);
};

