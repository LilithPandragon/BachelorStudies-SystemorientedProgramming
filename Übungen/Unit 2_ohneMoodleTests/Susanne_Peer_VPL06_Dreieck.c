//----------------------------------------------------------------
// VPL 06 - Dreieck Angabe:
// Schreiben Sie eine Funktion flaecheDreieck(...),
// die den Flächeninhalt eines Dreiecks nach der folgenden Formel
// von Heron berechnet und zurückgibt.
//
// \sqrt{s(s-a)(s-b)(s-c)}
// s= \frac{a+b+c}{2}
//
// siehe https://www.arndt-bruenner.de/mathe/9/herondreieck.htm
//
// NOTE: Die Dreiecksungleichung besagt, dass die Länge jeder Seite
// eines Dreiecks kleiner sein muss als die Summe der Längen der
// anderen beiden Seiten.
//
// Übergeben Sie der Funktion die Werte von a,b und c als Variable
// vom Typ double.
//
// Für die schnelle Eingabe eines gültigen Dreiecks, verwenden Sie:
//                  a = 4, b = 6, c = 7,2
//
//----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Dreieck {
    double a;
    double b;
    double c;
};

// Dreiecksungleichung prüfen
int heronPruef(struct Dreieck dreieck) {
    if (dreieck.a <= 0 || dreieck.b <= 0 || dreieck.c <= 0) {
        return 0; // Seitenlänge nicht positiv
    }
    if (dreieck.a + dreieck.b <= dreieck.c || dreieck.a + dreieck.c <= dreieck.b || dreieck.b + dreieck.c <= dreieck.a) {
        return 0; // Dreiecksungleichung verletzt
    }
    return 1; // Gültiges Dreieck
}

double heronDreiecksflaeche(struct Dreieck dreieck) {
    double s = (dreieck.a + dreieck.b + dreieck.c) / 2;
    double dreiecksflaeche = sqrt(s * (s - dreieck.a) * (s - dreieck.b) * (s - dreieck.c));
    return dreiecksflaeche;
}

int main() {
    struct Dreieck dreieck;

    while (1) {
        printf("Geben Sie nun die Längen der Seiten des zu berechnenden Dreiecks ein: \n");
        printf("a = ");
        if (scanf("%lf", &dreieck.a) != 1) { // Überprüfen, ob die Eingabe numerisch ist
            printf("##### MEH - Ungültige Eingabe #####\nBitte geben Sie Zahlen für die Seitenlänge an.\n");
            while (getchar() != '\n'); // Puffer leeren - Eingaben zu verwerfen
            continue;
        }
        printf("b = ");
        if (scanf("%lf", &dreieck.b) != 1) {
            printf("##### MEH - Ungültige Eingabe #####\nBitte geben Sie Zahlen für die Seitenlänge an.\n");
            while (getchar() != '\n');
            continue;
        }
        printf("c = ");
        if (scanf("%lf", &dreieck.c) != 1) {
            printf("##### MEH - Ungültige Eingabe #####\nBitte geben Sie Zahlen für die Seitenlänge an.\n");
            while (getchar() != '\n');
            continue;
        }

        // Prüfen ob Eingaben gültiges Dreieck ergeben
        if (!heronPruef(dreieck)) {
            printf("##### MEH - Ungültige Eingabe #####\n Die von Ihnen eingegebenen Seitenlängen ergeben leider kein gültiges Dreieck.\n");
            printf("Versuchen Sie es nocheinmal und geben Sie nun die Seitenlängen erneut ein.\n");
        } else {
            break; //
        }
    }

    double dreiecksflaeche = heronDreiecksflaeche(dreieck);

    printf(" #### HURRAA #### \nDie Fläche des Dreiecks ist: %lf\n", dreiecksflaeche);

    return 0;
}
