//-------------------------------------------------------------------------------------
// Übung 2: Wait
// Erweitern sie das Programm aus der letzten Übung (Zombie), indem der
// Elternprozess auf die Beendigung des Kindprozesses wartet.
// Beenden sie den Kindprozess mit dem Status 47.
//
// Geben sie im Elternprozess die pid aus wait() und den Exitstatus
// des Kindprozesses aus.
//
// Ausgabeformat:
//    Waited for: <pid>, Exitstatus: 47
//
//-------------------------------------------------------------------------------------
//  Systemnahe Programmierung SWD21
//  Susanne Peer

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Forking error\n");
        return 1;
    } else if (pid == 0) {
        printf("Kinprozess pid: %d PPID: %d PID: %d\n", pid, getppid(), getpid());
        _exit(47);
    } else {
        printf("Elternprozess pid: %d PPID: %d PID: %d\n", pid, getppid(), getpid());

        int status;
        pid_t child_pid = wait(&status);
        printf("Waited for: %d, Exitstatus: %d\n", child_pid, WEXITSTATUS(status));
    }

    return 0;
}
