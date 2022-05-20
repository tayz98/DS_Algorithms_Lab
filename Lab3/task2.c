/**
 * Author: Alexander Nachtigal
 * Matrikel-Nr.: XXXXX
 * Version: 1.0
 * Creation-Date 16.05.2022
 * Description: this program contains linked lists and can also manage them.
 */

#include <stdlib.h>
#include <stdio.h>

// our struct template, can be accessed with they keyword "Listnode"
typedef struct listnode {
    int value;
    struct listnode *next;
} Listnode;

// pre declared functions
void listAdd(Listnode **, int);

void print_list(Listnode *, int);

void insert_element(Listnode *, int, int);

void delete_list(Listnode **);

int search_element(Listnode *, int);

void delete_element(Listnode *, int);

int count_elements(Listnode *);

/**
 * The main function is used for creating and managing linked lists by calling other functions.
 * @return 0
 */
int main(void) {

    Listnode *pStart = NULL;
    printf("Amount of elements in the list is: %d \n", count_elements(pStart));
    // filling the list with data(values)
    listAdd(&pStart, 8);
    listAdd(&pStart, 9);
    listAdd(&pStart, 77);
    listAdd(&pStart, 67);
    listAdd(&pStart, 75);
    listAdd(&pStart, 74);
    listAdd(&pStart, 30);
    listAdd(&pStart, 27);
    listAdd(&pStart, 17);
    print_list(pStart, count_elements(pStart));
    printf("Amount of elements in the list is: %d \n", count_elements(pStart));

    // testing the functions
    insert_element(pStart, 2, 100);
    print_list(pStart, 7);
    delete_element(pStart, 2);
    printf("the position of the searched element in the list is: %d\n", search_element(pStart, 30));
    print_list(pStart, 3);
    delete_list(&pStart);
    print_list(pStart, 7);



    return 0;
}

/**
 * Specify the struct pointer which list elements will be counted.
 * Counts the elements by checking if the element is null and afterwards incrementing the amount variable.
 * If the list has no elements, it returns 0.
 * @param count
 * @return amount (the amount of the elements in the list)
 */
int count_elements(Listnode *count) {
    int amount = 0;
    while (count != NULL) { // runs through every element in the list and checks if it is NULL
        amount++;
        count = count->next;
    }
    return amount;
}

/**
 * Specify the (double)struct pointer and value which will be added to the linked list.
 * The function adds the given value to the end of the list.
 * @param pStart
 * @param value
 */
void listAdd(Listnode **pStart, int value) {

    Listnode *new = (Listnode *) malloc(sizeof(Listnode)); // allocate memory to the node
    Listnode *last = *pStart; // run pointer, which will be needed for the while loop below.

    new->value = value;

    new->next = NULL; // last element in the list must be NULL.

    // if the linked list is empty, make the new node as pStart.
    if (*pStart == NULL) {
        *pStart = new;
        return;
    }

    // traversing till the last element.
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new; // changes the last element of the list with the new variable, which has the given value.
}

/**
 * Specify the pointer and an int of how many elements in the list that must be printed.
 * The function checks, if the list is empty. If it is, it prints "list is null".
 * It also checks, if the given int is too high, and prints "bad input".
 * @param print
 * @param count
 */
void print_list(Listnode *print, int count) {
    Listnode *current = print; // our run variable to run through the list.

    if (current == NULL) {
        printf("list is NULL\n");
        return;
    }

    if (count > count_elements(print)) {
        printf("bad input, please enter a valid number corresponding to the amount of elements in the list\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", current->value);
        current = current->next;
    }
    return;
}

/**
 * specify the struct pointer of the linked list, the int value and the int position where the values should be inserted.
 * If the list is empty or the given position doesn't exist in the list, the function won't do anything.
 * @param insert
 * @param position
 * @param val
 */
void insert_element(Listnode *insert, int position, int val) {
    if (insert == NULL) {
        return;
    }
    if (position > count_elements(insert)) {
        printf("bad input\n");
        return;
    }
    Listnode *pTemp, *p; // pTemp is the run variable, p is the new element.
    p = (Listnode *) malloc(sizeof(Listnode));
    p->value = val;
    pTemp = insert; // set the run variable to the address of pStart.
    for (int i = 1; i < position - 1; i++) {
        pTemp = pTemp->next; // it loops until we are one element away of the given position variable.
    }
    p->next = pTemp->next; // p->next shows to the same next element as pTemp->next.
    pTemp->next = p; // let pTemp->next be the address of the p with new value.
    return;
}

/**
 * Specify the linked list (double pointer) which will be deleted.
 * This function free's every element of the linked lists.
 * After freeing, it sets the pointer to NULL to make the list globally NULL.
 * @param delete
 */
void delete_list(Listnode **delete) {
    // current and next are temporary pointers.
    Listnode *current = *delete;
    Listnode *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *delete = NULL;
}

/**
 * specify the linked list (pointer) and the position which will be deleted of the list.
 * If the list is empty or the given position is invalid, the function will return without changing anything. *
 * @param delete
 * @param position
 */
void delete_element(Listnode *delete, int position) {
    if (delete == NULL) {
        return;
    }
    if (position > count_elements(delete)) {
        printf("bad input\n");
        return;
    }
    Listnode *pTemp = delete;
    if (position == 0) {
        printf("Value of the deleted element is: %d \n", pTemp->value);
        delete = delete->next;
        pTemp->next = NULL;
        free(pTemp);
    } else {
        for (int i = 1; i < (position-1); i++) {
            pTemp = pTemp->next;
        }
        Listnode *del = pTemp->next;
        pTemp->next = pTemp->next->next;
        printf("Value of the deleted element is: %d \n", del->value);
        del->next = NULL;
        free(del);
    }
}

/**
 * Specify the value which will be searched in the linked lists.
 * If the list is empty or does not contain the element, the number '0' will be returned.
 * @param element
 * @param val
 * @return the position of the element in the linked list will be returned as an int.
 */
int search_element(Listnode *element, int val) {
    if (element == NULL) {
        printf("Either the element doesn't exist in the list, or the list doesn't exist.\n");
        return 0;
    }
    int position = 1;
    while ((element != NULL) && (element->value != val)) {
        element = element->next;
        position++;
    }
    if (element->value != val) {
        return 0;
    }
    return position;
}