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

/* solution for a): each digit of a single decimal number will be put into a new integer array.
 *                  this procedure will be done for all existing decimal numbers.
 *                  a new int array, where the arithmetic operation will be saved, is needed.
 *                  each matching element of the arrays will be added up.
 *                  if the result is less than 10, then save the result to the matching element of the new array.
 *                  if the result is 10, then save '0' to the matching element of the new array AND add 1 to the next element of the new array.
 *                  if the result is above 10, then save the first digit (from right) to the matching element of the new array AND the second digit to the next element of the new array.
 *                  repeat the steps above until the array is out of elements/numbers.
 */
//solutions for b,c,d,e
int main (void){

    return 0;
}