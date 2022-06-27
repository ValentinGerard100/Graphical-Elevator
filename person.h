#ifndef PERSON_H
#define PERSON_H

//represente the starting floor and the arrival floor of a person
typedef struct _Person {
    int src;
    int dest;
}Person;

//represente a list of persons with the last person and the list of persons who are ahead
typedef struct _PersonList {
    Person* person;
    struct _PersonList *next;
} PersonList;

//create a person from his starting floor and his arrival floor
Person* createPerson(int src, int dest);

//add a person to the list using a previous list
PersonList* insert(Person *p, PersonList *list);

#endif
