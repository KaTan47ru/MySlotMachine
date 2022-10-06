#include <iostream>
#include "SFML/Graphics.hpp"
#include "SlotMachine.h"
#include "StaticState.h"
#include "SpiningState.h"
#include "PrizeState.h"
/*
    NB Я знаю о существовании умных указателей. Код писался с идеей продемонстрировать умение ручной работы с памятью.
*/
int main()
{

    srand(time(NULL));
    //�������� ���� ��� �������, ���� � ����� close, ��� ��� �� ����� ��������� flex ������ ��� ���������
    sf::RenderWindow* window= new sf::RenderWindow(sf::VideoMode(1000, 800), "Cruel Gods Spins",sf::Style::Close);
    //������������� ���� ������, ������� � ���������� ����� ����������� �����������
    SlotMachine * Machine = new SlotMachine;
    //������������� ���������
    State* initStane = new StaticState(Machine);
    State* spinState = new SpiningState(Machine);
    State* prizeState = new PrizeState(Machine);
    //���������� ��������� � ��������� �����
    initStane->setNextState(spinState);
    spinState->setNextState(prizeState);
    prizeState->setNextState(initStane);
    //������ ���������. � ������ ������� ������ � ������ ���������
    initStane->runRoutine(window);
    delete initStane;
    delete spinState;
    delete prizeState;
    delete Machine;
    delete window;
    return 0;
}