// --------------------------------------------------------------------------------
// VPL 04 - Wochentag Angabe:
// Schreiben Sie ein Programm, das eine Zahl zwischen 1 und 7 einliest
// und den entsprechenden Wochentag als Text ausgibt.
// Das Programm soll solange Zahlen einlesen bis die Zahl 0 eingegeben wurde.
// Bei Eingabe einer ungültigen Zahl soll eine entsprechende Meldung ausgegeben werden.
//
// Verwenden Sie eine while Schleife, ein switch Statement und die Funktion
// scanf() dazu.
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>

int main() {
    int daynumber;

  //  printf("Halli Hallo. Geben Sie bitte eine Zahl zwischen 1 und 7 ein (Geben Sie 0 ein um das Programm zum Beenden): ");
    scanf("%d", &daynumber);

    while (daynumber != 0) {
        if (daynumber < 1 || daynumber > 7) {
            printf(" MEH - Ungültige Eingabe. Versuchen Sie es bitte nocheinmal und geben Sie eine Zahl zwischen 1 und 7 ein.\n");
        } else {
            switch (daynumber) {
                case 1:
                    printf("Montag\n");
                    break;
                case 2:
                    printf("Dienstag\n");
                    break;
                case 3:
                    printf("Mittwoch\n");
                    break;
                case 4:
                    printf("Donnerstag\n");
                    break;
                case 5:
                    printf("Freitag\n");
                    break;
                case 6:
                    printf("Samstag\n");
                    break;
                case 7:
                    printf("Sonntag\n");
                    break;
            }
        }
     //  printf("Bitte geben Sie eine Zahl zwischen 1 und 7 ein (Geben Sie 0 ein um das Programm zum Beenden): ");
        scanf("%d", &daynumber);
    }

   // printf("0\n");

    return 0;
}
