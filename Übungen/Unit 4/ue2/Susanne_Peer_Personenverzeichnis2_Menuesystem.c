//-----------------------------------
// 2. Aufgabe : Personenverzeichnis 2 - Menüsystem
// Wir erweitern das Programm nun um ein einfaches Menüsystem und eine Möglichkeit zur Datenerfassung.
// Das Menüsystem besteht darin, dass wir einzelne Zeichen als Befehle von stdin abfragen
// Implementieren sie folgende Befehle:
//
// n ... Neue Person anlegen
//      → Daten für eine Person via stdin erfassen
//      → Personenrecord anlegen und in Liste einfügen
//
// a ... Liste ausgeben
//      → Liste aller Personen ausgeben (wie gehabt)
//
// e ... Ende
//      → Programm beenden
//
// Geben sie den Speicher der durch die Liste belegt wird,
// vor dem Beenden des Programms frei.
//
// Hinweis: Wenn Sie für das Abfragen der Menüeingaben getchar() verwenden, sollten
// Sie nicht vergessen, dass die Eingaben aus dem Befehlsbuchstaben
// und '\n' bestehen.
// Vergessen Sie nicht beim Einlesen der Daten und der Befehle überschüssige
// Zeichen zu entfernen.
// Beispiel:
// void readText(char *line, int len) {
// if (fgets(line, len, stdin)) {
// line[strcspn(line, "\n")] = '\0';
// if (strlen(line) >= len-1)
// while ((getchar()) != '\n'); ------------>>clear buffer!!!!!!!
// }
// }
//----------------------------------------------------------------------
// Systemnahe Programmierung
// Susanne Peer SWD21


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct person {
    int id;
    char vorname[255];
    char nachname[255];
    char telefon[50];
    char email[255];
    struct person *next;
};

typedef struct person person;

person *start = NULL;


/*
 * Alle Personeneinträge in der Liste ausgeben.
*/
void personenAusgeben(person *start) {
    person *current = start;
    while (current != NULL) {
        printf("ID: %d, Vorname: %-10s, Nachname: %-10s, Telefon: %-15s, Email: %s\n",
               current->id, current->vorname, current->nachname, current->telefon, current->email);
        current = current->next;
    }
}
/*
 * Heap-Speicher für eine Personen-Struktur allozieren und Daten
 * in den Speicherbereich schreiben.
 */
person *personAnlegen(char *vorname, char *nachname, char *telefon, char *email) {
    person *newPerson = (person*)malloc(sizeof(person));
    if (newPerson == NULL) {
        printf("Speicher konnte nicht alloziert werden.\n");
        exit(1);
    }
    static int idCounter = 1;
    newPerson->id = idCounter++;
    strcpy(newPerson->vorname, vorname);
    strcpy(newPerson->nachname, nachname);
    strcpy(newPerson->telefon, telefon);
    strcpy(newPerson->email, email);
    newPerson->next = NULL;
    return newPerson;
}
/*
 * Einen neuen Personenrecord am Ende der Liste anfügen.
 */
void personEinfuegen(person *p) {
    if (start == NULL) {
        start = p;
    } else {
        person *current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = p;
    }
}

void memoryFreeing(person *start) {
    person *current = start;
    while (current != NULL) {
        person *temp = current;
        current = current->next;
        free(temp);
    }
}

// Bereitgestellte Funktion von Hr. Lindner
void readText(char *line, int len) {
    if (fgets(line, len, stdin)) {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) >= len-1) {
            while ((getchar()) != '\n');
        }
    }
}

int main() {
    char command;
    char input[255];

    do {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n~~~~~~ Menuechen Steuerung ~~~~~~\n");
        printf("n ... neue Person ist daimt anzulegen\n");
        printf("a ... die Liste der Personen anzeigen\n");
        printf("e ... Programm beenden.\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Geben Sie nun Ihre Wahl ein: ");
        scanf(" %c", &command);

        switch (tolower(command)) {
            case 'n':
                printf("Vorname ");
                readText(input, sizeof(input));
                char vorname[255];
                strcpy(vorname, input);

                printf("Nachname ");
                readText(input, sizeof(input));
                char nachname[255];
                strcpy(nachname, input);

                printf("Telefonnummer ");
                readText(input, sizeof(input));
                char telefon[50];
                strcpy(telefon, input);

                printf("Email ");
                readText(input, sizeof(input));
                char email[255];
                strcpy(email, input);

                personEinfuegen(personAnlegen(vorname, nachname, telefon, email));
                break;

            case 'a':
                printf("\nDies ist eine Liste aller angelegten Personen:\n");
                personenAusgeben(start);
                break;

            case 'e':
                memoryFreeing(start);
                printf("Das Programm wird nun beendet. Gute Nacht!\n");
                break;

            default:
                printf("Diese ist leider nicht gültig als Eingabe, versuch es nocheinmal.\n");
        }
    } while (tolower(command) != 'e');

    return 0;
}
