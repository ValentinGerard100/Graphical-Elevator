#include "person.h"
#include <stdlib.h>

Person* create_person(int src, int dest){
    Person* res = NULL; // to init the pointer
    res = malloc(sizeof(Person)); // memory allocation
    if(res == NULL){
        exit(0);
    } // to test if the memory allocation is successful
    res->src = src;
    res->dest = dest;
    return res;
}

List* init_list(){
    List* res = NULL;
    Element* e = NULL;
    res = malloc(sizeof(List));// memory allocations
    e = malloc(sizeof(Element));
    if(res == NULL || e == NULL){
        exit(0); // to test if the  both memory allocations are successful
    }
    e->person = NULL; // the first person of the linked list is NULL
    e->next = NULL; // the following of the linked list is NULL
    res->first = e; 
    return res;
}

void insert(Person* person, List* list){
    Element* e = NULL;
    e = malloc(sizeof(Element));// memory allocation
    if(e == NULL){
        exit(0);
    }// to test if the memory allocation is successful
    e->person = person;
    e->next = list->first; // put this new element at the begining of the linked list 
    list->first = e; //move of the pointer on the new first element of the linked list
}