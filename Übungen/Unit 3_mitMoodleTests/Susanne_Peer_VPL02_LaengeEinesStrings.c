//----------------------------------------------------------------
// VPL 02 - Länge eines Strings Angabe:
// Schreiben sie eine Funktion my_strlen(char string[]), welche die Länge eines Strings ohne den sizeof() Operator zu verwenden, berechnet.
// Verwenden sie dazu eine Schleife und testen sie die Funktion mit folgender Zeichenkette:
//    char text[100]="FH JOANNEUM";
//
//Ausgabe:
//    String: “FH JOANNEUM“ Länge:11
//----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>

int my_strlen(char *string) {
    char *pointi = string;
    while (*pointi != '\0') {
        pointi++;
    }
    return pointi - string;
}

int main() {
    char text[100] = "FH JOANNEUM";
    printf("String: \"%s\" Länge: %d\n", text, my_strlen(text));
    return 0;
}
