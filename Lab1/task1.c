//
// Created by Alexander Nachtigal on 03.04.2022.
// Link to github: https://github.com/tayz98/DS_Algorithms_Lab/blob/main/Lab1/task1.c

/* Task(german text):
 * Die Rechenregeln zur Addition zweier mehrstelliger Dezimalzahlen sind Ihnen sicher schon seit
    Ihrer Grundschulzeit bekannt. Ihre Aufgabe ist es nun, ein Programm zu schreiben, welches zwei
    mehrstellige Dezimalzahlen mit Hilfe dieser Regeln addiert. Dabei dürfen Sie den Additionsoperator (+) verwenden – allerdings nur, um einzelne Ziffern der Zahlen unter Berücksichtigung
    des Übertrags zu addieren. Die dabei zu lösenden Teilaufgaben lauten wie folgt:
    a) Formulieren Sie (Worte, kein C-Code) einen möglichst klar verständlichen Algorithmus für
       die Addition von zwei mehrstelligen Dezimalzahlen, der als Vorlage für ein Additions-Programm
       genutzt werden kann. Testen Sie den Algorithmus von Hand an einem Beispiel.
    b) Schreiben Sie eine Funktion ziffer, die Ihnen die i-te Ziffer einer Integer-Zahl als Rückgabewert liefert.
       Beispiel: ziffer(1234, 1) = 4, ziffer(1234, 2) = 3, ziffer(1234, 3) = 2, ziffer(1234, 5) = 0.
       Tipp: Sie können dazu den Divisions- (/) und Modulo-Operator (%) verwenden
    c) Schreiben Sie eine Funktion anzahlZiffern, die Ihnen die Anzahl der Ziffern einer IntegerZahl liefert. Beispiel: anzahlZiffern(12345) = 5
    d) Schreiben Sie eine Funktion add(), die zwei Integer-Zahlen mit Ihrem unter a. beschriebenen
       Algorithmus addiert und das Ergebnis als Rückgabewert liefert. Das Programm sollte die unter b.
       und c. erstellten Funktionen verwenden.
    e) Überprüfen Sie Ihr Programm mit einem Testprogramm, das Ihre Additionsfunktion für 10000
       verschiedene Zahlenpaare (z.B. mit Hilfe zweier verschachtelter for-Schleifen) einsetzt und mit
       dem Ergebnis des Standardoperators (+) vergleicht. Falls Ihre Additionsfunktion ein anderes
       Ergebnis liefert als der Standardoperator soll eine Fehlermeldung ausgegeben werden.
       Korrigieren Sie Ihr Programm gegebenenfalls, bis alle Fehlermeldungen eliminiert sind.*/

/* solution for a):
 */

//solutions for b,c,d,e:
#include <stdio.h>
int digit(int, int);
int amountOfDigits(int);
int add(int, int);

int main (void){
    printf("%d\n",digit(12345, 3));
    printf("%d\n", amountOfDigits(12345));
    printf("%d\n", add(12345, 54321));
    printf("%d\n", add(12345,12345));
    return 0;
}
// solution for b:
int digit(int number, int digit){
    for (int i = 1; i<=digit-1; i++)
    {
        number /= 10;
    }
    number = number % 10;
    int numberToReturn = number;
    return numberToReturn;
}
// solution for c:
int amountOfDigits(int number){
    int i = 0;
    while (number != 0){
        i++;
        number /= 10;
    }
    return i;
}

// solution for d:
int add(int number1, int number2){
    int result = 0;
    int digitcount = 1;
    int size;
    if(amountOfDigits(number1) == amountOfDigits(number2))
    {
        if ((digit(number1, amountOfDigits(number1) + digit(number2, amountOfDigits(number2)))) >=10)         // maybe not the cleanest or "smartest" code but fulfils the purpose for now I guess.
        {
            size = amountOfDigits(number1) + 1;
        } else {
            size = amountOfDigits(number1);
        }
    }
    if(amountOfDigits(number1) < amountOfDigits(number2)) {
        if ((digit(number1, amountOfDigits(number1) + digit(number2, amountOfDigits((number2)-1)))) >=10)    // stopped working here. what happens if you have a second carry over at number2.
        {
            size = amountOfDigits(number1) + 1; // copied pasted. needs to be re rewritten.
        } else {
            size = amountOfDigits(number1); // copied pasted. needs to be re rewritten.
        }
    }
    for (int i = 0; i <= size; i++)
    {
        result += (digit(number1, digitcount)+ digit(number2, digitcount));
        digitcount++;
    }
    return result;
}
