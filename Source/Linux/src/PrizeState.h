#pragma once
#include "State.h"
#include"SlotMachine.h"
// Третье сосояние машины. Начинается когда заканчивается вращение, перекращается при нажатии кнопки start
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

