#pragma once
#include "State.h"
#include"SlotMachine.h"
// Реализация интерфейса дя состояния 2.
class SpiningState :
    public State
{
    SlotMachine* slotMachineHandler;
    State* nextState;
public:
    SpiningState(SlotMachine*);
    virtual void  runRoutine(sf::RenderWindow* window);
    virtual void setNextState(State*);
};

