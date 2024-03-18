//----------------------------------------------------------------
// VPL 02 - ASCII Angabe:
// Lesen Sie mit der getchar() Funktion eine char Variable ein
// und geben Sie deren ASCII-Wert als Dezimalzahl und als
// Hexadezimalzahl aus.
//
// Beispiel:
// Zeichen eingeben: w
//
// Der ASCII Wert von w ist 119/0x77
// Der ASCII Wert von U ist 85/0x55
// Der ASCII Wert von 1 ist 49/0x31
// Der ASCII Wert von ? ist 63/0x3f
// Testen sie das Programm mit den Zeichen w, U, 1 und ?
//----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>

int main() {
    char ascii_wert;

    do {
        printf("Geben Sie bitte nun ein beliebiges Zeichen ein (Drücken Sie 'q' zum Beenden): ");
        ascii_wert = getchar();

        if(ascii_wert == 'q') {
            break; // Beende die Schleife, wenn 'q' eingegeben wurde
        }

        printf("Der ASCII Wert von %c ist in Dezimal: %d  und in Hexadezimal: 0x%x\n", ascii_wert, ascii_wert, ascii_wert);

        // Leere den Puffer, um überschüssige Eingaben zu vermeiden
        while (getchar() != '\n') {}

    } while (1); // Endlosschleife, wird durch break unterbrochen, wenn 'q' eingegeben wurde

    return 0;
}
