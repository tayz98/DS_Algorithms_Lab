/**
 * Author: Alexander Nachtigal
 * Matrikel-Nr.: XXXXX
 * Version: 1.0
 * Creation-Date 16.05.2022
 * Description: this programm contains a simple linked list and can also manage this list.
 */

#include <stdlib.h>
#include <stdio.h>

// our struct template
typedef struct listnode {
    int value;
    struct listnode *next;
} Listnode;

void print_list(Listnode*, int);
void insert_element(Listnode*, int, int);
void delete_list(Listnode*);
int search_element(Listnode*, int);

int main(void) {

    // create elements and fill them with data
    Listnode *pStart = NULL;
    pStart = (Listnode *) malloc(sizeof (Listnode));
    pStart->value = 10;
    pStart->next = (Listnode *) malloc(sizeof (Listnode));
    pStart->next->value = 20;
    pStart->next->next = (Listnode *) malloc(sizeof (Listnode));
    pStart->next->next->value = 30;
    pStart->next->next->next = (Listnode *) malloc(sizeof (Listnode));
    pStart->next->next->next->value = 40;
    pStart->next->next->next->next = (Listnode *) malloc(sizeof (Listnode));
    pStart->next->next->next->next->value = 50;
    pStart->next->next->next->next->next = (Listnode *) malloc(sizeof (Listnode));
    pStart->next->next->next->next->next->value = 60;
    pStart->next->next->next->next->next->next = (Listnode *) malloc(sizeof (Listnode));
    pStart->next->next->next->next->next->next->value = 70;
    pStart->next->next->next->next->next->next->next = NULL;
    // prints the list.
    print_list(pStart, 3);
    printf("the position of the searched element in the list is: %d\n", search_element(pStart, 30));
    insert_element(pStart, 2, 100);
    print_list(pStart,7);
    //inserts the element to the given position minus 1.
    // prints the list again to show that the insert function works.
    delete_list(pStart);
    return 0;
}

void print_list(Listnode *print, int count) {
    Listnode *current = print; // our run variable to run through the list.

    for (int i = 0; i<count; i++) {
        printf("%d\n", current->value);
        current = current->next;
    }
    return;
}

void insert_element(Listnode *insert, int position, int val) {
    Listnode  *pTemp, *p; // pTemp is the run variable, p is the new element.
    p->value = val;
    pTemp = insert; // set the run variable to the address of pStart.
    for (int i = 1; i<position-1; i++) {
        pTemp = pTemp->next; // it loops until we are one element away of the given position variable.
    }
    p->next = pTemp->next; // p->next shows to the same next element as pTemp->next.
    pTemp->next = p; // let pTemp->next be the address of the p with new value.
    return;
}

void delete_list(Listnode *delete) {
    free(delete);
    return;
}

int search_element (Listnode *element, int val) {
    int position = 1;
    while (element !=NULL && element->value != val) {
        element = element->next;
        position++;
    }
    return position;
}