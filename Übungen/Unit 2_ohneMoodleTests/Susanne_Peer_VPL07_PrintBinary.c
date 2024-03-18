// ----------------------------------------------
// VPL 07 - PrintBinary Angabe:
// Schreiben Sie eine Funktion printBinary(unsigned char c) die
// eine unsigned char Variable entgegen nimmt und diese in binärer
// Form ausgibt.
// Testen Sie die Funktion mit den Zahlen 10, 128 und 91 (in dieser
// Reihenfolge).
//
// Beispiel:
//    00001010
//    .....
//
// Hinweis:
// Benutzen Sie die Bitoperatoren um ein einzelnes Bit darzustellen und
// schieben Sie die Zahl nach rechts.
// Benutzen Sie Zeichenarithmetik um das darstellbare ASCII-Zeichen
// (0 oder 1) zu berechnen.
// Die Anzahl der Stellen des char Datentyps (Wert von CHAR_BIT)
// können Sie aus limits.h erfahren.
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21


// ----------------------------------------------
// VPL 07 - PrintBinary Angabe:
// Schreiben Sie eine Funktion printBinary(unsigned char c) die
// eine unsigned char Variable entgegen nimmt und diese in binärer
// Form ausgibt.
// Testen Sie die Funktion mit den Zahlen 10, 128 und 91 (in dieser
// Reihenfolge).
//
// Beispiel:
//    00001010
//    .....
//
// Hinweis:
// Benutzen Sie die Bitoperatoren um ein einzelnes Bit darzustellen und
// schieben Sie die Zahl nach rechts.
// Benutzen Sie Zeichenarithmetik um das darstellbare ASCII-Zeichen
// (0 oder 1) zu berechnen.
// Die Anzahl der Stellen des char Datentyps (Wert von CHAR_BIT)
// können Sie aus limits.h erfahren.
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>
#include <limits.h>

// unsigned char in binärer Form ausgeben
void printBinary(unsigned char c) {
    // Anzahl Stellen des chars
    int num_bits = CHAR_BIT;

    for (int i = num_bits - 1; i >= 0; i--) {
        unsigned char bit = (c >> i) & 1;
        // Berechnung ASCII-Wert für 0 oder 1
        char ascii_value = bit ? '1' : '0';
        printf("%c", ascii_value);
        // Leerzeichen drucken
        if ((num_bits - i) % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

int test() {
    // Tests mit 10, 128 und 91
    unsigned char test1 = 10;
    unsigned char test2 = 128;
    unsigned char test3 = 91;

    printf("#### Beispiele ####\n");
    printf("10 ist binär:\n");
    printBinary(test1);

    printf("\n128 ist binär:\n");
    printBinary(test2);

    printf("\n91 ist binär:\n");
    printBinary(test3);

    return 0;
}

int main() {

    test();

    unsigned char inputNum;
    // Benutzer:innen eingabe von 0-255 möglich
    printf("#### Binärumwandlungsspaß ####\n Geben Sie nun bitte eine Zahl ein : ");
    scanf("%hhu", &inputNum);

    printf(" Binär ist das: \n");
    printBinary(inputNum);

    return 0;
}
