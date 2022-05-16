/**
 * Author: Alexander Nachtigal
 * Matrikel-Nr.: XXXXX
 * Version: 1.0
 * Creation-Date 16.05.2022
 * Description: this programm contains a simple linked list and can also manage this list.
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct listnode {
    int value;
    struct listnode *next;
} Listnode;

void print_list(Listnode*, int);
void insert_element(Listnode*, int);
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
    print_list(pStart, 3);
    insert_element(pStart, 2);
    return 0;
}

void print_list(Listnode *pStart, int count) {
    Listnode *current = pStart;

    for (int i = 0; i<count; i++) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void insert_element(Listnode *pStart, int position) {
    Listnode  *pTemp;
    for (int i = 1; i<=position; i++) {
        pTemp = pTemp->next;
    }

    pStart -> next = pTemp -> next;
    pTemp -> next = pStart;
}