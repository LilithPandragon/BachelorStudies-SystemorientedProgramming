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

int main(){
    
    char ascii_wert;
    
    printf ("Bitte geben Sie ein Zeichen ein: ");
    
    ascii_wert = getchar();
    
    printf("Der ASCII Wert von %c ist %d/%#x", ascii_wert,ascii_wert,ascii_wert);
    
    return 0;
}
