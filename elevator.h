#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "person.h"

typedef  struct _Elevator {
    int capacity;
    int currentFloor;
    List* persons;  //persons who are in the elevator
} Elevator;

Elevator* create_elevator(int capacity, int floor, List* list);

void exit_elevator(Elevator* e);

void enter_elevator(Elevator* e, List* waitingList);

#endif