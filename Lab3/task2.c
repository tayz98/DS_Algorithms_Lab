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

void listAdd(Listnode**, int);
void print_list(Listnode*, int);
void insert_element(Listnode*, int, int);
void delete_list(Listnode**);
int search_element(Listnode*, int);

int main(void) {

    Listnode *pStart = NULL;
    listAdd(&pStart, 8);
    listAdd(&pStart, 9);
    listAdd(&pStart, 77);
    listAdd(&pStart, 67);
    listAdd(&pStart, 75);
    listAdd(&pStart, 74);
    listAdd(&pStart, 73);
    listAdd(&pStart, 27);
    listAdd(&pStart, 17);

    // create elements and fill them with data


    // using the functions
    print_list(pStart, 7);
    insert_element(pStart, 2, 100);
    print_list(pStart, 3);
    delete_list(&pStart);
    printf("the position of the searched element in the list is: %d\n", search_element(pStart, 30));
    print_list(pStart,7);

    return 0;
}
void listAdd(Listnode **pStart, int value) {

   Listnode* new = (Listnode *) malloc(sizeof (Listnode));
   Listnode *last = *pStart;

   new->value = value;

   new->next = NULL;

   if (*pStart == NULL) {
       *pStart = new;
       return;
   }
   while (last->next != NULL) {
       last = last->next;
   }

   last->next = new;
}

void print_list(Listnode *print, int count) {
    Listnode *current = print; // our run variable to run through the list.

    if (current == NULL) {
        printf("list is NULL");
        return;
    }

    for (int i = 0; i<count; i++) {
        if (current == NULL) {
            printf("test");
            return;
        }
        printf("%d\n", current->value);
        current = current->next;
    }
    return;
}

void insert_element(Listnode *insert, int position, int val) {
    if (insert == NULL) {
        return;
    }
    Listnode  *pTemp, *p; // pTemp is the run variable, p is the new element.
    p = (Listnode *) malloc(sizeof (Listnode));
    p->value = val;
    pTemp = insert; // set the run variable to the address of pStart.
    for (int i = 1; i<position-1; i++) {
        pTemp = pTemp->next; // it loops until we are one element away of the given position variable.
    }
    p->next = pTemp->next; // p->next shows to the same next element as pTemp->next.
    pTemp->next = p; // let pTemp->next be the address of the p with new value.
    return;
}

void delete_list(Listnode **delete) {
    Listnode *current = *delete;
    Listnode *next;
    while (current!=NULL) {
        next = current ->next;
        free(current);
        current = next;
    }
    *delete = NULL;
}

int search_element (Listnode *element, int val) {
    if (element == NULL) {
        printf("Either the element doesn't exist in the list, or the list doesn't exist. ");
        return 0;
    }
    int position = 1;
    while ((element !=NULL) && (element->value != val)) {
        element = element->next;
        position++;
    }
    if (element->value != val) {
        return 0;
    }
    return position;
}