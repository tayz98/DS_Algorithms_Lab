/******************************************************************
* EUKLID
******************************************************************/
#include <stdio.h>

int euklidIterativ(int, int);
int euklidIterativ2(int, int);
int euklidRekursiv(int, int);
int euklidRekursiv2(int, int);

int main(void) {
    int a = 6270;
    int b = 8295;
    printf("%d\n", euklidIterativ(a, b));
    printf("%d\n", euklidIterativ2(a, b));
    printf("%d\n", euklidRekursiv(a, b));
    printf("%d\n", euklidRekursiv2(a, b));
    return 0;
}
// slow
int euklidIterativ(int a, int b) {
   while ( a != b ) {
       if (a > b) {
           a -= b;
       } else {
           b -= a;
       }
   }
   return a;
}

// fast
int euklidIterativ2(int a, int b) {
    int temp, r;
    if (a < b ) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//slow
int euklidRekursiv(int a, int b){
    if (a == b) {
        return a;
    } else if (a > b) {
        return euklidRekursiv(a-b, b);
    } else {
        return euklidRekursiv(a, b-a);
    }
}

//fast
int euklidRekursiv2(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return euklidIterativ2(b, a % b);
    }
}
