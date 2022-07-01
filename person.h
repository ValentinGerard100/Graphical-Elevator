#ifndef PERSON_H
#define PERSON_H

typedef struct _Person {
    int src;
    int dest;
} Person;

Person* create_person(int src, int dest);

//linked list 
typedef struct _Element {
    Person* person;
    struct _Element* next;
} Element;

//to find the begining of the linked list
typedef struct _List {
    Element* first;  // it's a pointer on the first element of the linked list
} List;

//to create a empty linked list which point on NULL
List* init_list();

//insert a new element on the linked list
void insert(Person* person, List* list);



#endif
