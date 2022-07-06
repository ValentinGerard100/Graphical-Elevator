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
    res = malloc(sizeof(List));
    if(res == NULL){
        exit(0); // to test if the  memory allocation is  successful
    }
    Element* e = NULL;// the first element of each linked list is NULL
    res->first = e;
    res->nbElement = 0; 
    return res;
}

void insert(Person* person, List* list){
    Element* e = NULL;
    e = malloc(sizeof(Element));
    if(e == NULL){
        exit(0);
    }// to test if the memory allocation is successful
    e->person = person;
    e->next = list->first; // put this new element at the begining of the linked list 
    list->first = e; //move of the pointer on the new first element of the linked list
    list->nbElement += 1;
}

//to copy a list at an other adress 
List* copy_list(List* l){
    List* res = init_list();
    List* reverse = init_list();
    Element* m_p = l->first;  //pointer which move from the begining to the end of the linkedlist
    while(m_p != NULL){
        insert(m_p->person,reverse);
        m_p = m_p->next;
    }
    //reverse is now a copy of the linkdlist but in reverse order
    while(reverse->first != NULL){
        insert(reverse->first->person, res);
        reverse->first = reverse->first->next;
    }
    // res is now a copy of the linkedlist in the good order 
    return res;
}  