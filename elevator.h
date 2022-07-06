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

typedef struct _Building {
    int nbFloor;
    List** waitingLists;// waitingLists[i] is the waitingList of the floor number i
    Elevator* elevator;
}Building;

//remove people who need to leave the elevator is the current floor is the target floor
void exit_elevator(Building* b);

//put firsts people from the waitinglist of the floor if the elevator is not full and the current floor is the target floor
void enter_elevator(Building* b);

Building* create_building(int nbFloor, List** waitingLists, Elevator* elevator);

//move the elevator to go at the target floor,then call exit_elevator and enter_elevator
void stepElevator(Building* b);

#endif