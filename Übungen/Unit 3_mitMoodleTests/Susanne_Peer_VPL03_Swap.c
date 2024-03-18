//----------------------------------------------------------------
// VPL 03 - Swap Angabe:
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
 //   printf("###### SWAPING MAGIC ######\n\n");
    int val1 = 1, val2 = 8;
    printf("a:%d b:%d\n", val1, val2);
    swap(&val1, &val2);
    printf("a:%d b:%d\n", val1, val2);

    int val3 = 98172232 , val4 = 77;
    printf("a:%d b:%d\n", val3, val4);
    swap(&val3, &val4);
    printf("a:%d b:%d\n", val3, val4);

    int val5 = 34, val6 = 31092;
    printf("a:%d b:%d\n", val5, val6);
    swap(&val5, &val6);
    printf("a:%d b:%d\n\n", val5, val6);

    return 0;
}
