//---------------------------------------------------------------------------
//      Uebung 2: Dateisystem
// Schreiben sie ein Programm welches das aktuelle Verzeichnis ausliest und alle darin enthaltenen Einträge auf stdout ausgibt.
// Verwenden sie folgendes Ausgabeformat:
// Dateiname     Typ Permission Zeit
// Dateiname: padded auf z.B: 50 Zeichen links ausgerichtet.
// Typ: 'F' Datei, 'D' Verzeichnis, 'L' Link
// Permission: Wenn für den Besitzer ausführbar, dann 'X' sonst leer.
// Zeit: Modification time
//
//
// Beispiel:
//
// popen.c                                            F   Mon Jan 15 15:11:29 2024
// ..                                                 D X Tue Apr 23 20:29:16 2024
// .                                                  D X Wed Apr 24 08:23:06 2024
// DIR                                                F X Wed Apr 24 08:23:06 2024
// dir.c                                              F   Wed Apr 24 08:23:02 2024
// signal.c                                           F   Mon Jan 15 15:11:29 2024
// pipe.c                                             F   Mon Jan 15 15:11:29 2024
//---------------------------------------------------------------
// Systemnahe Programmierung SWD21
//
// Susanne Peer, SWD21

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_FILENAME_LEN 50

char getFileType(mode_t mode) {
    if (S_ISREG(mode)) return 'F';
    else if (S_ISDIR(mode)) return 'D';
    else if (S_ISLNK(mode)) return 'L';
    else return '?';
}

char getPermission(mode_t mode) {
    if (mode & S_IXUSR) return 'X';
    else return ' ';
}

char* formatTime(time_t time) {
    static char buffer[80];
    strftime(buffer, 80, "%a %b %d %H:%M:%S %Y", localtime(&time));
    return buffer;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    
    dir = opendir(".");
    if (!dir) {
        perror("Error when opening directory");
        return EXIT_FAILURE;
    }

    printf("Beispiel:\n\n");

    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &file_stat) == -1) {
            perror("Error reading file informations");
            continue;
        }

        char filename[MAX_FILENAME_LEN + 1];
        strncpy(filename, entry->d_name, MAX_FILENAME_LEN);
        filename[MAX_FILENAME_LEN] = '\0';

        char file_type = getFileType(file_stat.st_mode);
        char permission = getPermission(file_stat.st_mode);
        char* time_str = formatTime(file_stat.st_mtime);

        printf("%-50s %-2c %c %-24s\n", filename, file_type, permission, time_str);
    }
    
    closedir(dir);
    return EXIT_SUCCESS;
}
