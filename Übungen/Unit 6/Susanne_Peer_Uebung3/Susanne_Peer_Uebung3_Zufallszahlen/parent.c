//-------------------------------------------------------------
// Übung 3 - Zufallszahlen 
// 
// Schreiben sie ein Programm worker, das eine Zufallszahl zwischen 0 und 100 erzeugt und diese als Exitstatus zurückgibt.
// Verwenden sie zur Erzeugung der Zufallszahlen die Funktionen srand() und rand().
//
// Das Programm worker erwartet eine Integer-Zahl als Argument und initialisiert den Zufallszahlgenerator mit der Summe aus dem Argument und seiner PID.
// Der worker soll mit printf() das Argument und die erzeugte Zufallszahl auf stdout ausgeben.
//
// Schreiben sie ein Hauptprogramm parent, das  10 Child-Prozesse erzeugt (Schleife) und in jedem Child das Programm worker ausführt.
// Übergeben sie worker als Argument eine Zahl (Schleifenindex) zwischen 0 und 9.
// Beachten sie, dass der Pfad zum Programm worker vollständig ist.
//
//Das Hauptprogramm wartet auf die Child-Prozesse und gibt die PID und Zufallszahl jedes childs (= Exit-Status) in folgender Form auf stdout aus:
//
//    <childpid>: <zufallszahl>
//
// Geben sie abschließend die größte gefundene Zahl aus.
// Achten sie darauf, dass die Ausgaben der Kindprozesse von der des Hauptprogramms (parent) unterschieden werden können (z.B.: unterschiedliches Präfix).
//----------------------------------------------------------------------------
//  Systemnahe Programmierung SWD21
//  Susanne Peer



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int max_random_number = -1;

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            char index_str[2];
            sprintf(index_str, "%d", i);
            execl("./worker", "worker", index_str, NULL);
            exit(1); 
        } else if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            exit(1);
        }
    }

    for (int i = 0; i < 10; i++) {
        int status;
        pid_t child_pid = wait(&status);
        if (WIFEXITED(status)) {
            int child_exit_status = WEXITSTATUS(status);
            printf("<%d>: %d\n", child_pid, child_exit_status);
            if (child_exit_status > max_random_number) {
                max_random_number = child_exit_status;
            }
        }
    }

    printf("Maximum random number found: %d\n", max_random_number);

    return 0;
}

