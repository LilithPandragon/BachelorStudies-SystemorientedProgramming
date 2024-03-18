#include <stdio.h>

int main() {
    char ascii_wert;
    printf("##### ASCII SPASS #####\n\n");
    // printf("Geben Sie nun bitte ein beliebiges Zeichen ein (Drücken Sie 'q' um das Programm zu Beenden): ");

    ascii_wert = 'w';
    printf("\nDer ASCII Wert von %c ist\nin Dezimal: %d und\nin Hexadezimal: 0x%x\n\n", ascii_wert, ascii_wert, ascii_wert);

    ascii_wert = 'U';
    printf("ASCII von %c ist\nin Dezimal: %d und\nin Hexadezimal: 0x%x\n\n", ascii_wert, ascii_wert, ascii_wert);

    ascii_wert = '1';
    printf("ASCII von %c ist\nin Dezimal: %d und\nin Hexadezimal: 0x%x\n\n", ascii_wert, ascii_wert, ascii_wert);

    ascii_wert = '?';
    printf("ASCII von %c ist\nin Dezimal: %d und\nin Hexadezimal: 0x%x\n\n", ascii_wert, ascii_wert, ascii_wert);

    // do {
    //     printf("Geben Sie nun bitte ein beliebiges Zeichen ein (Drücken Sie 'q' um das Programm zu Beenden): ");
    //     ascii_wert = getchar();

    //     if(ascii_wert == 'q') {
    //         break;
    //     }

    //     printf("\nASCII von %c ist\nin Dezimal: %d und\nin Hexadezimal: 0x%x\n\n", ascii_wert, ascii_wert, ascii_wert);

    //     // Puffer ausleern
    //     while (getchar() != '\n') {}

    // } while (1); // Endlosschleife -- durch q Eingabe abgebrochen

    return 0;
}
