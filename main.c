
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

#include "elevator.h"
#include "person.h"

#define HEIGHT 30
#define WIDTH 40
#define PERSON_WIDTH 3

// YOU NEED TO ENTER 'q ' TO EXIT THE DISPLAY WINDOW


void DisplayPersonList(WINDOW *win, List *list, int level, int offset) {
    List* copy = copy_list(list); // we need a copy of the linkedlist at an other adress because display a list destroy it
    while(copy->first != NULL) {
        // display 25 for a person going from floor 2 to floor 5
        mvwaddch(win, level, offset, '0' + copy->first->person->src);
        mvwaddch(win, level, offset+1, '0' + copy->first->person->dest);
        copy->first = copy->first->next;
        offset+= PERSON_WIDTH;
    }
}


void DisplayElevator(WINDOW *win, int nbFloor, Elevator *e, int offset) {
    //Display elevator
    // [23 24 31 30 42]
    int level = 3*(nbFloor - e->currentFloor); // 3 lines per level
    mvwaddch(win, level, offset+1, '[');
    DisplayPersonList(win, e->persons, level, offset+2);
    mvwaddch(win, level, offset+2+ (PERSON_WIDTH*e->capacity), ']');
}

void DisplayBuilding(WINDOW *win, Building *b) {
    int offset = 1;
    // to display walls
    // |                |
    // |[23 24 31 30 42]| 31 32
    // |                |
    int right_wall = offset + 3 + (PERSON_WIDTH*b->elevator->capacity);
    for(int i=0; i < b->nbFloor; ++i) {//for each floor
        int level = 3*i+1;
        mvwaddch(win,level,  offset,'|');
        mvwaddch(win,level+1,offset,'|');
        mvwaddch(win,level,  right_wall,'|');
        mvwaddch(win,level+1,right_wall,'|');
    }
    for(int i=offset+1; i < right_wall; i++) {
        mvwaddch(win,3*(b->nbFloor)+1,i,'_');
    }
    // to display the elevator
    DisplayElevator(win, b->nbFloor, b->elevator, offset);
    //to display the waitinglists
    for(int i=0; i < b->nbFloor; i++) {
        int level = 3*(b->nbFloor - i);
        DisplayPersonList(win,b->waitingLists[i], level, right_wall + 2);
    }
}


int main(){
    srand(time(0));   // should only be called once
    // generate list of waiting persons
    int  nbFloor = 5;
    List **waitingLists = NULL;
    waitingLists = malloc(nbFloor*sizeof(List*));
    if(waitingLists == NULL){
        exit(0);//test  if the memory allocation is successfull
    }
    for(int currentFloor=0; currentFloor < nbFloor; currentFloor++) {//create a waitinglist for each floor
        waitingLists[currentFloor] = init_list();
        int nbPerson = 5; // 5 persons in the waiting list
        for(int j=0 ; j<nbPerson ; j++) { // create 5 persons and put them in the waitinglist
            int dest = rand() % (nbFloor);
            Person *p = create_person(currentFloor, dest);
            insert(p,waitingLists[currentFloor]);
        }
    }

    // Initialize building and elevator
    int capacity = 3;
    int currentFloor = 0;
    List* empty = init_list();//because the elevator is empty at the begining
    Elevator *elevator = create_elevator(capacity, currentFloor , empty);
    Building *building = create_building(nbFloor, waitingLists, elevator);

    // Initialize ncurse display
    initscr(); // initialize ncurses
    noecho();  // do not display in window the pressed keys
    halfdelay(2);

    WINDOW *win = newwin(HEIGHT, WIDTH, 0, 0);
 

    // Animation loop
    bool run=true;
    while(run) {
        // Generate people in function of input (or quit if 'q')
        int input = wgetch(win);
        if(input == 'q') {
            run = false;
        }
        else {
            int level = input - '0'; // the user gives the target floor
            if(0 <= level && level < nbFloor) { //to control that user gives a floor which exist
                building->elevator->targetFloor = level;
            }

            // Update state machine of elevator !!!!
            stepElevator(building);//put the elevator at the target floor (to go from 1 to 3 it need 2 passage in the while loop)
            wclear(win);   // clear display area
            box(win, 0,0); // display border of window
            DisplayBuilding(win, building);
            wrefresh(win); // actual display function
        }
    }
    endwin(); // correct ending of ncurses
    return 0;
}


    
