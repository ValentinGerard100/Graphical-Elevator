#include "elevator.h"
#include <stdlib.h>

Elevator* create_elevator(int capacity, int floor, List* list){
    Elevator* res  = NULL;
    res = malloc(sizeof(Elevator));
    if(res == NULL){
        exit(0);//test if the memory allocation is succesfull
    }
    res->targetFloor = floor;//i decided that at the creation of the elevator the target floor is the current floor 
    res->capacity = capacity;
    res->currentFloor = floor;
    res->persons = list;
    return res;
}

void exit_elevator(Building* b){
    List* stay = init_list();//linkedlist of people who stay in the elevator
    while(b->elevator->persons->first != NULL){
        if(b->elevator->persons->first->person->dest != b->elevator->currentFloor){
            insert(b->elevator->persons->first->person, stay);
        }
        b->elevator->persons->first = b->elevator->persons->first->next;
    }
    List* stay_reverse = init_list(); //if i don't reverse this linkedlist the order of persons inside the elevator is changing when i display the elevator
    while(stay->first != NULL){
        insert(stay->first->person, stay_reverse);
        stay->first = stay->first->next;
    }//to reverse the order
    b->elevator->persons = stay_reverse;
}

void enter_elevator(Building* b){
    int floor = b->elevator->currentFloor;
    while(b->waitingLists[floor]->first != NULL && b->elevator->persons->nbElement != b->elevator->capacity){// elevator souldn't be full and the waitinglist shouldn't be  empty
        insert(b->waitingLists[floor]->first->person, b->elevator->persons);
        b->waitingLists[floor]->first = b->waitingLists[floor]->first->next;//move the header of the linkedlist
        b->waitingLists[floor]->nbElement = b->waitingLists[floor]->nbElement -1;
    }
}


Building* create_building(int nbFloor, List** waitingLists, Elevator* elevator){
    Building* res  = NULL;
    res = malloc(sizeof(Building));
    if(res == NULL){
        exit(0);//test if the memory allocation is successfull
    }
    res->nbFloor = nbFloor;
    res->waitingLists = waitingLists;
    res->elevator = elevator;
    return res;
}

void stepElevator(Building* b){
    //if the elevator is at the target floor
    if(b->elevator->currentFloor == b->elevator->targetFloor){
        exit_elevator(b);//exit before enter 
        enter_elevator(b);
    }
    //the elevator sould go at the target floor before use exit_elevator and enter_elevator
    else{
        if(b->elevator->currentFloor < b->elevator->targetFloor){
            b->elevator->currentFloor += 1;
        }
        else{
            b->elevator->currentFloor += -1;
        }
    }
}