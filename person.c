#include "person.h"
#include <stdlib.h>

//create a person from his starting floor and his arrival floor
Person* createPerson(int src, int dest){
    Person* res = malloc(sizeof(Person));
    res-> src = src;
    res-> dest = dest;
    return res;
}

//add a person to the list using a previous list
PersonList* insert(Person *p, PersonList *list){
    PersonList* res = malloc(sizeof(Person));
    res-> person = p;
    res-> next = list;
    return res;
}
