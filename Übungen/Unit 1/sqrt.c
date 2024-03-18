//---------------------------------------------------------------------------
//  VPL 00 - Sqrt Angabe:
// Schreiben Sie ein Programm, das die Quadratwurzel der Zahl
// 3638 berechnet und ausgibt.
// Verwenden Sie dazu die Bibliotheksfunktion sqrt().
// Die Definition von sqrt() können sie mit man sqrt nachschlagen.
//
// Verwenden Sie als Ausgabeformat (in der Funktion printf):  %.2lf
// Die Ausgabe soll so aussehen: Die Wurzel von 3638 ist <Ergebnis>
//
// Hinweis: #include Dateien nicht vergessen.
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21





#include <stdio.h>
#include <math.h>

int main() {
    double wurzi = sqrt(3638);

    printf("Die Wurzel von 3638 ist %.2lf\n", wurzi);

    return 0;
}
