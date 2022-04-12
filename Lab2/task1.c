//
// Created by Alexander Nachtigal on 12.04.2022.
//

#include <stdio.h>
#include <time.h>

int fibonacci(int);
int main(void){
    clock_t tm1, tm2;
    tm1 = clock();
    fibonacci(50);
    tm2 = clock();
    printf("Dauer %.2f Sekunden \n", (double) (tm2-tm1)/CLOCKS_PER_SEC);
    return 0;
}

// solution for a
int fibonacci(int fibo){
    if (fibo == 0) return 0;
    if (fibo == 1) return 1;
    return (fibonacci(fibo-1) + fibonacci(fibo-2));

}