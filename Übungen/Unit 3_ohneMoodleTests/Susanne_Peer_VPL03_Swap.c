//----------------------------------------------------------------
// Schreiben Sie eine Funktion swap, die zwei int Werte vertauscht.
// Die Signatur sollte so aussehen: void swap(int *a, int *b);
//
// Testen Sie die Funktion für mindestens 3 Wertepaare und
// geben Sie die Werte vor und nach der Vertauschung aus.
//----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

//----------------------------------------------------------------
// Schreiben Sie eine Funktion swap, die zwei int Werte vertauscht.
// Die Signatur sollte so aussehen: void swap(int *a, int *b);
//
// Testen Sie die Funktion für mindestens 3 Wertepaare und
// geben Sie die Werte vor und nach der Vertauschung aus.
//----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>

// Vertauschen zweier int Werte durch Adressentausch
void swap(int *a, int *b) {
    int mark = *a;
    *a = *b;
    *b = mark;
}

int main() {
    printf("###### SWAPING MAGIC ######\n\n");
    int val1 = 10, val2 = 20;
    printf("Vor dem Zauber:\n Wert Nr. 1 = %d\n Wert Nr. 2 = %d\n", val1, val2);
    swap(&val1, &val2);
    printf("Nach dem Zauber:\n Wert Nr. 1 = %d\n Wert Nr. 2 = %d\n\n", val1, val2);

    int val3 = -5, val4 = 100;
    printf("Vor dem Zauber:\n Wert Nr. 3 = %d\n Wert Nr. 4 = %d\n", val3, val4);
    swap(&val3, &val4);
    printf("Nach dem Zauber:\n Wert Nr. 3 = %d\n Wert Nr. 4 = %d\n\n", val3, val4);

    int val5 = 0, val6 = 50;
    printf("Vor dem Zauber:\n Wert Nr. 5 = %d\n Wert Nr. 6 = %d\n", val5, val6);
    swap(&val5, &val6);
    printf("Nach dem Zauber:\n Wert Nr. 5 = %d\n Wert Nr. 6 = %d\n\n", val5, val6);

    return 0;
}
