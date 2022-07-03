#include "elevator.h"
#include <stdlib.h>

Elevator* create_elevator(int capacity, int floor, List* list){
    Elevator* res  = NULL;
    res = malloc(sizeof(Elevator));
    if(res == NULL){
        exit(0);
    }
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