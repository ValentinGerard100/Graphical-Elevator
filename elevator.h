#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "person.h"

typedef  struct _Elevator {
    int capacity;
    int currentFloor;
    int targetFloor;
    List* persons;  //persons who are in the elevator
} Elevator;

Elevator* create_elevator(int capacity, int floor, List* list);

void exit_elevator(Elevator* e);

void enter_elevator(Elevator* e, List* waitingList);

typedef struct _Building {
    int nbFloor;
    List** waitingLists;
    Elevator* elevator;
}Building;

Building* create_building(int nbFloor, List** waitingLists, Elevator* elevator);

void stepElevator(Building* b);
#endif