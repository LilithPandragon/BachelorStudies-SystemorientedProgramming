//--------------------------------------------------------------------------------------------------------------
// Übung 2
// Erweitern sie das Programm aus der letzten Übung, so dass es die Werte
// "num_bytes" (Typ integer) und "total" (Typ String) aus einer
// Konfigurationsdatei einliest.
// Die Ausgabe soll auf num_bytes Zeichen beschränkt werden, falls die Variable
// num_bytes in der Konfigurationsdatei enthalten und >0 ist.
// Falls die Variable total (max. Länge 1024) in der Konfigurationsdatei enthalten
// ist, soll am Ende der Ausgabe eine Zusammenfassung wie folgt ausgegeben
// werden:
//      <inhalt von total>\n
//      Datei: <Dateiname>
//      Ausgegebene Zeichen: <anzahl zeichen>
// Lesen sie den Pfad der Konfigurationsdatei aus der Umgebungsvariable
// "CONFIG_FILE" ein. Wenn diese nicht existiert, soll das Programm eine Meldung
// ausgeben und abbrechen.
// Beispiel: Variable definieren in Shell export CONFIG_FILE="./test.cfg"
//------------------------------------------------------------------------------------------------------------------
// Systemnahe Pogrammierung SWD21
//
// Susanne Peer

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void readConfig(char *configFile, int *numBytes, char *total)
{
    FILE *fp = fopen(configFile, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Failed to open configuration file %s.\n", configFile);
        exit(1);
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strncmp(line, "num_bytes", 9) == 0)
        {
            *numBytes = atoi(strchr(line, '=') + 1);
        }
        else if (strncmp(line, "total", 5) == 0)
        {
            strncpy(total, strchr(line, '=') + 1, BUFFER_SIZE);
            total[strcspn(total, "\n")] = '\0';
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        fprintf(stderr, "Error: No file specified. Please specify file.\n");
        return 1;
    }

    char *configFile = getenv("CONFIG_FILE");
    if (configFile == NULL)
    {
        fprintf(stderr, "Error: CONFIG_FILE environment variable not set.\n");
        return 1;
    }

    int numBytes = -1;
    char total[BUFFER_SIZE] = "";
    readConfig(configFile, &numBytes, total);

    char buffer[BUFFER_SIZE];
    int bytesRead;
    int totalBytesRead = 0;

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        fprintf(stderr, "Error: Failed to open file %s.\n", argv[1]);
        return 1;
    }

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (numBytes > 0 && totalBytesRead + bytesRead > numBytes)
        {
            bytesRead = numBytes - totalBytesRead;
        }
        if (write(STDERR_FILENO, buffer, bytesRead) != bytesRead)
        {
            perror("write");
            close(fd);
            fprintf(stderr, "Error: Failed writing to stderr.\n");
            return 1;
        }
        totalBytesRead += bytesRead;
        if (numBytes > 0 && totalBytesRead >= numBytes)
        {
            break;
        }
    }

    if (bytesRead == -1)
    {
        perror("read");
        close(fd);
        fprintf(stderr, "Error: Failed reading from file %s.\n", argv[1]);
        return 1;
    }

    close(fd);

    if (strlen(total) > 0)
    {
        printf("\n%s\nDatei: %s\nAusgegebene Zeichen: %d\n", total, argv[1], totalBytesRead);
    }

    return 0;
}
