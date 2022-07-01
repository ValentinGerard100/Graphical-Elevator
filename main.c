#include <stdio.h>
#include "person.h"
#include "elevator.h"

int main(){
    // test of source file person.c
    Person* p_1 = create_person(1, 2); 
    printf("person comes from %d and goes to %d\n",p_1->src, p_1->dest);
    List* l = init_list();
    insert(p_1, l);
    printf("first person of the list comes from %d and goes to %d\n", l->first->person->src, l->first->person->dest);
}
    
