//---------------------------------------------------------------------------
//  VPL 01 - Kleinbuchstaben Angabe:
// Definieren Sie eine char Variable und initialisieren Sie diese
// mit dem Kleinbuchstaben 'q'.
//
// Wandeln Sie den Inhalt der Variable unter Benutzung arithmetischer
// Operationen in einen Großbuchstaben um.
// Das Programm sollte folgende Ausgabe erzeugen:
//    Kleinbuchstabe: q Großbuchstabe: Q
// Hinweis
// Die Buchstaben A-Z und a-z sind im ASCII Code sequenziell abgelegt.
//    A-Z entspricht dezimal 65-90
//    a-z entspricht dezimal 97-122
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>

int main() {
    char kleinerbuchstabe = 'q';
    char grosserbuchstabe;


    if (kleinerbuchstabe >= 'a' && kleinerbuchstabe <= 'z') {
        grosserbuchstabe = kleinerbuchstabe - ('a' - 'A');
    } else {
        grosserbuchstabe = kleinerbuchstabe;
    }

    printf("Kleines Buchstabi: %c Großes Buchstabi: %c\n", kleinerbuchstabe, grosserbuchstabe);

    return 0;
}
