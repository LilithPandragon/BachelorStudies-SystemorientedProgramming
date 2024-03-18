//----------------------------------------------------------------
// VPL 03 - Schaltjahr Angabe:
// Schreiben Sie ein Programm, das prüft, ob ein Jahr ein Schaltjahr ist.
// Das Jahr soll als int mit scanf() eingelesen werden.
//
// Folgende Regeln gelten für Schaltjahre:
//  Ist die Jahreszahl durch 400 teilbar, ist es ein Schaltjahr
//  Ist die Jahreszahl durch 100 teilbar aber nicht durch 400, ist es ein Schaltjahr.
//  Ist die Jahreszahl durch 4 teilbar aber nicht durch 100, dann ist es ein Schaltjahr.
//  In allen anderen Fällen ist das Jahr kein Schaltjahr.
//----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21



#include <stdio.h>

int main() {
    int checkyear;


    printf("Bitte geben Sie das zu prüfende Jahr ein: "); //Benutzer:innen Eingabeaufforderung
    scanf("%d", &checkyear);


    if (checkyear % 400 == 0) { //Prüfung Jahr durch 400 teilbar
        printf("HURRA %d ist ja doch ein Schaltjahr!\n", checkyear);
    } else if (checkyear % 100 == 0) { // Prüfung Jahr durch 100 teilbar
        printf("HURRA %d ist ja doch ein Schaltjahr!\n", checkyear);
    } else if (checkyear % 4 == 0) { //Prüfung Jahr durch 4 teilbar
        printf("HURRA %d ist ja doch ein Schaltjahr!\n", checkyear);
    } else { // wenn nichts erfüllt
        printf("Oh weh leider ist %d kein Schaltjahr.\n", checkyear);
    }

    return 0;
}
