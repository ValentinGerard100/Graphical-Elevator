#include "elevator.h"
#include <stdlib.h>

Elevator* create_elevator(int capacity, int floor, List* list){
    Elevator* res  = NULL;
    res = malloc(sizeof(Elevator));
    if(res == NULL){
        exit(0);
    }
    res->targetFloor = floor;//i decided that at the creation of the elevator the target floor is the current floor 
    res->capacity = capacity;
    res->currentFloor = floor;
    res->persons = list;
    return res;
}

void exit_elevator(Elevator* e){
    List* stay = init_list();
    Element* current = e->persons->first;
    while(current != NULL){
        if(current->person->dest != e->currentFloor){
            insert(current->person, stay);
        }
        current = current->next;
    }
    e->persons = stay;
}

void enter_elevator(Elevator* e, List* waitingList){
    while(waitingList->first != NULL && e->persons->nbElement != e->capacity){
        insert(waitingList->first->person, e->persons);
        waitingList->first = waitingList->first->next;
        waitingList->nbElement = waitingList->nbElement -1;
    }
}

Building* create_building(int nbFloor, List** waitingLists, Elevator* elevator){
    Building* res  = NULL;
    res = malloc(sizeof(Building));
    if(res == NULL){
        exit(0);
    }
    res->nbFloor = nbFloor;
    res->waitingLists = waitingLists;
    res->elevator = elevator;
    return res;
}

void stepElevator(Building* b){
    if(b->elevator->currentFloor == b->elevator->targetFloor){
        exit_elevator(b->elevator);
        enter_elevator(b->elevator, b->waitingLists[b->elevator->currentFloor]);
        //we can also ask for the next targetFloor here and update the waitinglist
    }
    else{
        if(b->elevator->currentFloor < b->elevator->targetFloor){
            b->elevator->currentFloor += 1;
        }
        else{
            b->elevator->currentFloor += -1;
        }
    }
}