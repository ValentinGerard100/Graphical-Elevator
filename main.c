#include <stdio.h>
#include "person.h"
#include "elevator.h"
//while(current != NULL){
        //if(current->person->dest != e->currentFloor){
            //insert(current->person, stay);
        //}
        //current = current->next;
int main(){
    // test of source file person.c
    Person* p_1 = create_person(1, 1); 
    Person* p_2 = create_person(2,2);
    Person* p_3 = create_person(3,3);
    Person* p_4 = create_person(4,4);
    List* l = init_list();
    insert(p_1, l);
    insert(p_2, l);
    List* w = init_list();
    insert(p_3, w);
    insert(p_4, w);
    Elevator* e = create_elevator(3,2,l);
    printf("before enter the first person in the elevator goes to %d\n",e->persons->first->person->dest);
    enter_elevator(e, w);
    printf("after enter the first person in the elevator goes to %d\n",e->persons->first->person->dest);
    printf("after enter the second person in the elevator goes to %d\n",e->persons->first->next->person->dest);
    printf("there are %d persons in the elevator\n",e->persons->nbElement);
    exit_elevator(e);
    printf("after exit there are %d persons in the elevator\n",e->persons->nbElement);
    
}
    
