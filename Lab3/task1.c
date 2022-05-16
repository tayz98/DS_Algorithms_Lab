//
// Created by Alex on 26.04.2022.
//

#include <stdlib.h>
#include <stdio.h>


typedef struct beispiel{
    int data;
    struct beispiel *pNext;
} Listnode;

int main(void) {
    // with structure variables:
    Listnode element1, element2;
    element1.pNext = &element2;
    element2.pNext = &element1;

    element1.data = 5;
    printf("%d \n", element1.data);
    (*element2.pNext).data = 10;
    printf("%d \n", element1.data);
    element2.pNext->data =12;
    printf("%d \n", element1.data);

    // with dynamic memory allocation and pointer
    Listnode *pElement1, *pElement2;
    pElement1 = (Listnode *) malloc(sizeof (Listnode));
    if (pElement1 == NULL) {
        printf("Memory allocation went wrong.");
        return -1;
    }
    // printf("%d\n", pElement1->data); random number
    pElement1->data=25;
    printf("%d \n", pElement1->data);

    pElement2 = (Listnode *) malloc(sizeof (Listnode));
    if (pElement1 == NULL) {
        printf("Memory allocation went wrong.");
        return -1;
    }

    pElement2->data=50;
    printf("%d \n", pElement2->data);

    pElement1->pNext = pElement2;
    pElement2->pNext = pElement1;

    pElement1->pNext->data= 100;
    pElement2->pNext->data = 200;

    printf("%d \n", pElement1->data);
    printf("%d \n", pElement2->data);

    free(pElement1);
    free(pElement2);
    return 0;
}