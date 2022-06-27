#include <stdio.h>
#include "person.h"

int main(){
    Person* p_1 = createPerson(1, 2);
    Person* p_2 = createPerson(2, 3);
    printf("the first one comes from %d floor and goes to %d floor\n", p_1->src, p_2->src);
    PersonList* list_1 = insert(p_1, NULL);
    printf("the last person in the list comes from %d floor and goes to %d floor\n", list_1->person->src, list_1->person->dest);
    PersonList* list_2 = insert(p_2, list_1);
    printf("the last person in the list comes from %d floor and goes to %d floor\n", list_2->person->src, list_2->person->dest);  
}

