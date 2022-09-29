#pragma once
#include "State.h"
#include"SlotMachine.h"
class StaticState :
    public State
{
    SlotMachine* slotMachineHandler;
    State* nextState;
public:
    StaticState(SlotMachine *);
    virtual void  runRoutine(sf::RenderWindow* window);
    virtual void setNextState(State*);
};

