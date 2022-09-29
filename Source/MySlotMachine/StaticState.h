#pragma once
#include "State.h"
#include"SlotMachine.h"
// класс описывающий состояние ожидания действий игрока. Первое Состояние по ТЗ.
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

