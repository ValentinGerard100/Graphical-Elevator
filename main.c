#include <stdio.h>
#include "person.h"
#include "elevator.h"
#include "stdlib.h"
//while(current != NULL){
        //if(current->person->dest != e->currentFloor){
            //insert(current->person, stay);
        //}
        //current = current->next;
int main(){
    // test of source file person.c
    Person* p_1 = create_person(0, 0); 
    Person* p_2 = create_person(1,1);
    Person* p_3 = create_person(2,2);
    Person* p_4 = create_person(3,3);
    List* l = init_list();
    insert(p_1, l);
    insert(p_2, l);
    List* w = init_list();
    insert(p_3, w);
    insert(p_4, w);
    Elevator* e = create_elevator(3,1,l);
    List** waitinglists = NULL;
    waitinglists = malloc(sizeof(List**));
    if(waitinglists == NULL){
        exit(0);
    }
    waitinglists[0] = l;
    waitinglists[1] = w;
    Building* b = create_building(1, waitinglists, e);
    printf("at the floor 1 the first person goes to %d\n", b->waitingLists[1]->first->person->dest);
    stepElevator(b);
}
    
