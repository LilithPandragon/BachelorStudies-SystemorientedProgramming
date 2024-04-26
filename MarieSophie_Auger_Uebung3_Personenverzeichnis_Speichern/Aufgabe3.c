/*
Systemnahe Programmierung SS 2024
Marie-Sophie Auger
Matrikelnummer: 51809590
Übung 3 Beispiel Personenverzeichnis Speichern und Lesen
*/

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

person *start=NULL;

static int id = 0;
char dateiname[255];


 // read len-1 characters
void readText(char *line, int len) {
    if (fgets(line, len, stdin)) {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) >= len-1)
        while ((getchar()) != '\n');
    }
}

/*
 * Alle Personeneinträge in der Liste ausgeben.
 */
void personenAusgeben() {
    
    printf("Ausgabe der Personeneinträge der Liste: \n");
    printf("ID\t| Vorname\t  | Nachname\t | Telefon\t| Email\n");
    printf("------------------------------------------------------------------------\n");
    person *aktuell = start;
    while (aktuell != NULL) {
        printf("%d\t| %-15s | %s\t |  %s | %s\n", aktuell->id, aktuell->vorname, aktuell->nachname, aktuell->telefon, aktuell->email);
        aktuell = aktuell->next;
    }

    
}

/*
 * Heap-Speicher für eine Personen-Struktur allozieren und Daten 
 * in den Speicherbereich schreiben.
 */
person *personAnlegen() {
    char *vorname;
    char *nachname;
    char *telefon;
    char *mail;

    person *neuePerson = malloc(sizeof(person));


      if (neuePerson != NULL) { // Speicherprüfung

        neuePerson->id = ++id;
        printf("Vorname: ");
        readText(neuePerson->vorname, sizeof(neuePerson->vorname));
        printf("Nachname: ");
        readText(neuePerson->nachname, sizeof(neuePerson->nachname));
        printf("Telefon: ");
        readText(neuePerson->telefon, sizeof(neuePerson->telefon));
        printf("Email: ");
        readText(neuePerson->email, sizeof(neuePerson->email));
        neuePerson->next = NULL; // Am Ende der Liste einfügen
    }

    return neuePerson;
}

/*
 * Einen neuen Personenrecord am Ende der Liste anfügen.
 */
void personEinfuegen(person *startPerson) {
    
     if (start == NULL) {
        start = startPerson; // Wenn die Liste leer ist, wird die neue Person der Anfang der Liste
    } else {
        person *aktuell = start;
        while (aktuell->next != NULL) {
            aktuell = aktuell->next; // Zum Ende der Liste gehen
        }
        aktuell->next = startPerson;
    }
        
}


//Eigene Funktion zum Speicher freigeben, damit main nicht überladen
void speicherFreigeben(person *start) {
    person *aktuell = start;
    person *temp;

    while (aktuell != NULL) {
        temp = aktuell->next;
        free(aktuell);
        aktuell = temp;
    }
}

void dateiSpeichern(){
    printf("Bitte einen Dateinamen zum Speichern eingeben: ");
    readText(dateiname, sizeof(dateiname));

    FILE *datei = fopen(dateiname, "wb"); //wb = write binary

    person *aktuell = start;
    while (aktuell != NULL) {
        if (fwrite(aktuell, sizeof(person), 1, datei) != 1) {
            printf("Fehler beim Schreiben in die Datei.\n");
            fclose(datei);
            return;
        }
        aktuell = aktuell->next;
    }

    fclose(datei);

    printf("Datei %s gespeichert", dateiname);
}

void dateiLesen(){

    if (start != NULL) {
        printf("Es sind bereits Personen vorhanden. Möchten Sie diese löschen, bevor die Datei eingelesen wird? (j)Ja (n)Nein: ");
        char auswahl = getchar();
        while (getchar() != '\n'); // Eingabepuffer bis zum nächsten Zeilenumbruch leeren
        if (tolower(auswahl) == 'j') {
            speicherFreigeben(start); // Löscht alle vorhandenen Personen
            start = NULL; // Setzt den Startzeiger auf NULL, da die Liste jetzt leer ist
            printf("Alle vorhandenen Personen wurden gelöscht.\n");
        } else {
            printf("Es wurden keine Personen gelöscht. Bestehende Personen werden durch das Einlesen überschrieben.\n");
        }
    }

    printf("Bitte einen Dateinamen zum Einlesen eingeben: ");
    readText(dateiname, sizeof(dateiname));

    FILE *datei = fopen(dateiname, "rb"); // "rb" steht für Binärlesen (read binary)

     if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei zum Lesen.\n");
        return;
    }

    person personData;
    int anzahlGelesenerPersonen = 0;
  

    while (fread(&personData, sizeof(person), 1, datei) == 1) {
        person *neuePerson = malloc(sizeof(person));
        if (neuePerson != NULL) {
            *neuePerson = personData; // Kopieren der Daten von personData in die neue Person
            id++;
            neuePerson->id = id;
            neuePerson->next = NULL;
            personEinfuegen(neuePerson); // Fügt die neue Person der Liste hinzu
         
            
            anzahlGelesenerPersonen++;
        } else {
            printf("Fehler: Speicher konnte nicht alloziert werden.\n");
            fclose(datei);
            return;
        }
    }

   

    fclose(datei);

    printf("Datei %s eingelesen. Anzahl gelesener Personen: %d\n", dateiname, anzahlGelesenerPersonen);
}


int main() {

    while(1){
        printf("\nMenü:\n");
        printf("(n)Neue Person anlegen (a)Liste ausgeben (s)Liste als Datei speichern (l)Liste von Datei lesen (e)Ende\n");
        printf("Bitte wählen Sie einen Befehl: ");

        char befehl = getc(stdin);
        while (getchar() != '\n'); //n Eingabepuffer bis zum nächsten Zeilenumbruch leeren

        switch(befehl) {
                case 'n':
                    printf("Neue Person anlegen...\n");
                    personEinfuegen(personAnlegen());
                    break;
                case 'a':
                    personenAusgeben();
                    break;
                case 'e':
                    printf("Vielen Dank für die Verwendung unseres Telefonbuchs!\n");
                    speicherFreigeben(start);
                    exit(0);
                case 's':
                    dateiSpeichern();
                    break;
                case 'l':
                    printf("Datei wird eingelesen..\n");
                    dateiLesen();
                    break;
                default:
                    printf("Ungültige Eingabe. Bitte wählen Sie einen der verfügbaren Befehle.\n");
        }
        fflush(stdin); 
    }
    

 

}
