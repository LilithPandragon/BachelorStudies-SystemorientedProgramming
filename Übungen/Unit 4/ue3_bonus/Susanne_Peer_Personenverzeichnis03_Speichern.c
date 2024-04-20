//----------------------------------------------------------------------
// Aufgabe: Personenverzeichnis 3 - Speichern
// Ergänzen sie das Programm „Personenverzeichnis“ aus dem letzten Übungsbeispiel um die Funktionen
// „Speichern“ und „Lesen“.
//
// Die Funktion Speichern soll:
// Einen Dateinamen abfragen
// Die Personenliste in der Datei im Binärformat speichern.
//
// Die Funktion Lesen soll:
// Einen Dateinamen abfragen
// Die Personenliste aus der Datei lesen und die verkettete Liste wieder aufbauen.
//
// Mögliche Fehler wie Datei nicht gefunden usw. sollen abgefangen werden.
// Beim Lesen nicht vergessen den Zähler für die ID richtig zu setzen und falls bereits
// eine Liste existiert, nachzufragen was getan werden soll und diese gegebenenfalls zu löschen.
// 
// Aus Aufgabe 2
// 
// Beispiel:
// void readText(char *line, int len) {
// if (fgets(line, len, stdin)) {
// line[strcspn(line, "\n")] = '\0';
// if (strlen(line) >= len-1)
// while ((getchar()) != '\n'); ------------>>clear buffer!!!!!!!
// }
// }
//
// ----------------------------------------------------------------
// Systemnahe Programmierung SS24
//
// Susanne Peer SWD21


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struktur für eine Person
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

void savePersList(char *nameDatei) {
    FILE *file = fopen(nameDatei, "wb"); // Datei öffnen (Binärdaten schreiben)
    if (file == NULL) {
        printf("Oopsi. Leider trat ein Problem beim Speichern der Datei auf, bitte versuche es noch einmal.\n");
        return;
    }

    // Personenliste --> Datei 
    person *current = start;
    while (current != NULL) {
        fwrite(current, sizeof(person), 1, file);
        current = current->next;
    }

    fclose(file); // fclose schließt Datei
}

void readPersList(char *nameDatei) {
    FILE *file = fopen(nameDatei, "rb"); // Datei öffnen (Binärdaten lesen)
    if (file == NULL) {
        printf("Oopsi. Leider trat ein Problem beim Öffnen der Datei auf, bitte versuche es noch einmal.\n");
        return;
    }

    // wenn es schon eine Liste gibt --> löschen
    while (start != NULL) {
        person *temp = start;
        start = start->next;
        free(temp);
    }

    // Personen aus Datei --> Liste
    person temp;
    while (fread(&temp, sizeof(person), 1, file)) {
        person *newPerson = (person *)malloc(sizeof(person));
        if (newPerson == NULL) {
            printf("Oopsi. Es gab ein Problem beim Speichern der Person, bitte versuche es erneut.\n");
            return;
        }
        memcpy(newPerson, &temp, sizeof(person));
        newPerson->next = NULL;

        //Person einfügen
        if (start == NULL) {
            start = newPerson;
        } else {
            person *current = start;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newPerson;
        }
    }

    fclose(file); 
}

void personenAusgeben(person *start) {
    if (start == NULL) {
        printf("Das Personenverzeichnis ist momentan leider leer.\n");
        return;
    }

    printf("ID\tVorname\t\tNachname\t\tTelefon\t\tEmail\n");
    printf("-----------------------------------------------------------\n");
    person *current = start;
    while (current != NULL) {
        printf("%d\t%-15s\t%-15s\t%-15s\t%-15s\n", current->id, current->vorname, current->nachname, current->telefon, current->email);
        current = current->next;
    }
}

person *personAnlegen(char *vorname, char *nachname, char *telefon, char *email) {
    person *newPerson = (person *)malloc(sizeof(person));
    if (newPerson == NULL) {
        printf("Oopsi. Es gab ein Problem beim Anlegen einer neuen Person, bitte versuche es erneut.\n");
        return NULL;
    }

    static int idCounter = 1;
    newPerson->id = idCounter++;

    strcpy(newPerson->vorname, vorname);
    strcpy(newPerson->nachname, nachname);
    strcpy(newPerson->telefon, telefon);
    strcpy(newPerson->email, email);

    // Setze nächsten Pointer auf NULL! sonst zeigt er irgendwo hin (mit viel Glück dahin wo ich will aber wahrscheinlich nicht)
    newPerson->next = NULL;

    return newPerson;
}

void personEinfuegen(person *p) {
    if (p == NULL) {
        printf("Oopsi. Die Person, die eingefügt werden soll, ist ungültig.\n");
        return;
    }

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
    while (start != NULL) {
        person *temp = start;
        start = start->next;
        free(temp);
    }
}

void readText(char *line, int len) {
    if (fgets(line, len, stdin)) {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) >= len - 1) {
            while ((getchar()) != '\n'); // cache leeren!!!!
        }
    }
}

int main() {
    char command;
    char input[255];
    char dateiname[255]; 

    do {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n~~~~~~ Menuechen Steuerung ~~~~~~\n");
        printf("n ... neue Person ist damit anzulegen\n");
        printf("a ... die Liste der Personen anzeigen\n");
        printf("s ... die Liste der Personen speichern\n");
        printf("l ... die Liste der Personen laden\n");
        printf("e ... Programm beenden.\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Geben Sie nun Ihre Wahl ein: ");
        scanf(" %c", &command);

        switch (tolower(command)) {
            case 'n': {
                printf("Vorname: ");
                readText(input, sizeof(input));
                char vorname[255];
                strcpy(vorname, input);

                printf("Nachname: ");
                readText(input, sizeof(input));
                char nachname[255];
                strcpy(nachname, input);

                printf("Telefonnummer: ");
                readText(input, sizeof(input));
                char telefon[50];
                strcpy(telefon, input);

                printf("Email: ");
                readText(input, sizeof(input));
                char email[255];
                strcpy(email, input);

                personEinfuegen(personAnlegen(vorname, nachname, telefon, email));
                break;
            }

            case 'a':
                printf("\nDies ist eine Liste aller angelegten Personen:\n");
                personenAusgeben(start);
                break;

            case 's':
                printf("Gewünschten Dateinamen zum Speichern eingeben:\n");
                readText(dateiname, sizeof(dateiname));
                savePersList(dateiname);
                break;

            case 'l':
                printf("Geben Sie den Dateinamen zum Laden ein: ");
                readText(dateiname, sizeof(dateiname));
                readPersList(dateiname);
                break;

            case 'e':
                memoryFreeing(start);
                printf("Das Programm wird nun beendet. Gute Nacht!\n");
                break;

            default:
                printf("Ungültige Eingabe. Bitte versuchen Sie es erneut.\n");
        }
    } while (tolower(command) != 'e');

    return 0;
}
