/******************************************************************
* Projekt:Algorithmen und Datenstrukturen
* Dateiname: main.c
* Beschreibung: AuD – Aufgabenzettel 2 - ungerade Wochen/Aufgabe 1
* Autor: Alexander Nachtigal
* Matr.-Nr.: :)))))))))))))))
* Erstellt: April 2022
******************************************************************/

#include <time.h>

unsigned long long fibonacciRecursive(int index);
unsigned long long fibonacciIterative(int index);
double runtimeRecursive(int n);
double runtimeIterative(int n);
int biggestN(int maxSek);
clock_t tm1, tm2;

int main(void) {
    return 0;
}

// solution for a
unsigned long long fibonacciRecursive(int index) {
    if (index == 0) return 0;
    if (index == 1) return 1;
    return (fibonacciRecursive(index - 1) + fibonacciRecursive(index - 2));
}

// solution for c
unsigned long long fibonacciIterative(int index) {
    int n = index;
    unsigned long long first = 0, second = 1, next, c;
    for (c = 0; c <= n; c++) {
        if (c <= 1) {
            next = c;
        } else {
            next = first+second;
            first = second;
            second = next;
        }
    }
    return next;
}
// solution for b
double runtimeRecursive(int n) {
    tm1 = clock();
    fibonacciRecursive(4);
    tm2 = clock();
    return ((double)(tm2-tm1)/CLOCKS_PER_SEC);
}

double runtimeIterative(int n) {
    tm1 = clock();
    fibonacciRecursive(4);
    tm2 = clock();
    return ((double)(tm2-tm1)/CLOCKS_PER_SEC);
}

int biggestN(int maxSek) {
    tm1 = clock();
    int index = 0;
    while ((double)(clock()+tm1) / CLOCKS_PER_SEC <= maxSek) {
        fibonacciRecursive(index);
        index++;
    }
    return index;
}


