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


void printBinary(unsigned char c) {
    int num_bits = CHAR_BIT;

    for (int i = num_bits - 1; i >= 0; i--) {
        unsigned char bit = (c >> i) & 1;
        
        char ascii_value = bit ? '1' : '0';
        printf("%c", ascii_value);
    }
    printf("\n");
}

int main() {
    printBinary(10);
    printBinary(128);
    printBinary(91);

    return 0;
}
