//-------------------------------------------------------------------------------------
// Übung 1: Einen neuen Prozess erzeugen
//
// Schreiben sie ein Programm, das einen neuen Prozess mit fork() erzeugt.
// Geben sie die PID, PPID und den pid Wert aus fork() im jeweiligen Prozess mit printf() aus.
//
// Im Elternprozess: pid (Returnvalue) aus fork(), eigene PID und PPID,
// Im Kindprozess: pid (Returnvalue) aus fork(), eigene PID und PPID
//
// Ausgabeformat:
//
//    Elternprozess pid: 44982 PPID: 2407 PID: 44981
//    Kindprozess pid: 0 PPID: 44981 PID: 44982
//-------------------------------------------------------------------------------------
//  Systemnahe Programmierung SWD21
//  Susanne Peer 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    
    pid = fork();

    if (pid < 0) {
        printf("Forking error\n");
        return 1;
    } else if (pid == 0) {
        printf("Kinprozess pid: %d PPID: %d PID: %d\n", pid, getppid(), getpid());
    } else {
        printf("Elternprozess pid: %d PPID: %d PID: %d\n", pid, getppid(), getpid());
    }

    return 0;
}


