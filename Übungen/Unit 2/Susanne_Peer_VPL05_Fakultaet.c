// ---------------------------------------------------------
//  VPL 05 - Fakultät Angabe:
// Schreiben Sie ein Programm, das eine ganze Zahl einliest und
// deren Fakultät n! berechnet.
//
// Wobei:  n! = 1*2*3* ...n
// oder    n! = \prod_{k=1}^n k
// NOTE:
// wobei diese beiden Schreibweisen mathematisch äquivalent sind
// und das Produkt über alle ganzen Zahlen von 1 bis n bedeutet.
//
//
// Verwenden Sie eine for Schleife und scanf() dazu.
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // für atoi - ascii to integer

// Überprüfen ob Eingabe gültige Ganzzahl
bool isInteger(const char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if ((input[i] < '0' || input[i] > '9') && input[i] != '-') {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    int integervariable, f;
    long long fakultaet = 1;
    char input[20]; // Benutzer:innen Eingabe speichern (max. 19 Zeichen + 1 für Nullzeichen)

    bool validInput = false;

    while (!validInput) {
        printf("###### Fakultätrechnenspaß ###### \nGeben Sie nun bitte eine ganze Zahl ein: ");
        if (scanf("%19s", input) != 1 || !isInteger(input)) {
            printf("###### MEH - Ungültige Eingabe. ######\n\n");
        } else {
            integervariable = atoi(input);

            if (integervariable < 0) {
                printf("Fakultät ist leider für negative Zahlen nicht definiert :( .\n\n");
            } else {
                validInput = true;
            }
        }
    }

    for (f = 1; f <= integervariable; ++f) {
        fakultaet *= f; // n! = 1*2*3* ...n
    }

    printf("Uuuuuuuund die Fakultät von %d iiiiiiiist %lld\n", integervariable, fakultaet);

    return 0;
}
