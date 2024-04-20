// ----------------------
// 1. Aufgabe: Personenverzeichnis 1 - Basisfunktionen
// Implementieren sie im ersten Schritt folgende Funktionen:
// Eine neue Person anlegen:
// person *personAnlegen(char *vorname, char *nachname, char
//                              *telefon, char *mail);
//              → Speicher allozieren
//              → Daten in die Felder der Struktur kopieren
//
// Person in Liste einfügen:
// void personEinfuegen(person *p) ;
//              → fügt einen neuen Personen-Eintrag am Ende der Liste ein.
//
// Eine Liste der Personen ausgeben:
// Vom Startknoten bis zum Ende der Liste durchgehen und jedes
// Listenelement (Person) ausgeben.
// Pro Person eine Zeile ausgeben. Die Datenfelder einer Person
// mit fester Breite und links ausgerichtet ausgeben.
//
// Erzeugen Sie zum Testen mind. 7 Personeneinträge, die sie in die Liste einfügen.
// Geben Sie alle Elemente der Liste aus.
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Systemnahe Programmierung SS24
//
// Susanne Peer SWD21

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
  Personenliste Aufgabe 1
 */
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
  Alle Personeneinträge in der Liste ausgeben.
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
 Heap-Speicher für eine Personen-Struktur allozieren und Daten
 in den Speicherbereich schreiben.
 */
person *personAnlegen(char *vorname, char *nachname, char *telefon, char *mail) {
    person *newPersoni = (person*)malloc(sizeof(person));
    if (newPersoni == NULL) {
        printf("Fail memory could not be allocated.\n");
        exit(1);
}
    static int idCounter = 1;
    newPersoni->id = idCounter++;
    strcpy(newPersoni->vorname, vorname);
    strcpy(newPersoni->nachname, nachname);
    strcpy(newPersoni->telefon, telefon);
    strcpy(newPersoni->email, mail);
    newPersoni->next = NULL;
    return newPersoni;
}

/*
 Einen neuen Personenrecord am Ende der Liste anfügen.
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

int main() {
//person *start = NULL;
// Test ob hier was ausgegeben wird
// printf("startiiiii");

  personEinfuegen(personAnlegen("David", "Pfeifer", "06886167181", "DavidPfeifer@gmx.com"));
  personEinfuegen(personAnlegen("Doreen", "Baier", "06608191358", "DoreenBaier@cuvox.de"));
  personEinfuegen(personAnlegen("Martin", "Shuster", "06643231711", "MartinShuster@gmx.com"));
  personEinfuegen(personAnlegen("Felix", "Fink", "06814857140", "FelixFink@gmx.com"));
  personEinfuegen(personAnlegen("Dieter", "Schreiner", "06884132145", "DieterSchreiner@gmx.com"));
  personEinfuegen(personAnlegen("Dirk", "Saenger", "06508629090", "DirkSaenger@gmx.com"));
  personEinfuegen(personAnlegen("Martina", "Gloeckner", "06509758086", "MartinaGloeckner@gmx.com"));

personenAusgeben(start);

return 0;

}
