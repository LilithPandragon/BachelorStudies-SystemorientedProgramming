//----------------------------------------------------------
//      Uebung 1: Signale 
// 1) Implementieren sie eine Funktion in der Art
//    int setSignalHandler (int signal, void (*signalhandler)(int)) { … }
// welche den Funktionsparameter signalhandler als Signalhandler 
// für das Signal signal einrichtet.
//
// Verwenden Sie dazu die vorher besprochenen Funktionen
// sigemptyset(), sigaddset(), sigaction() und die Struktur sigaction.
//
// 2) Schreiben sie ein Programm, das folgende Schritte umsetzt:
// Einen Signalhandler für das Signal SIGINT mit der vorher implementierten
// Funktion setSignalHandler() einrichten.
// Der Signalhandler soll den Text "SIGINT aufgetreten." auf stdout ausgeben.
// Verwenden Sie zur Ausgabe im Signalhandler die sichere Low-level Funktion
//          write(STDOUT_FILENO,…)!
// Nach dem Einrichten des Signalhandlers soll mit sleep(2) etwas
// gewartet werden und anschließend mit raise() das Signal SIGINT an 
// den Prozess gesendet werden.
//
//Ungefähr so:
//  int main(int argc, char* argv[]){
//    setSignalHandler(SIGINT,...
//    sleep(2);
//    raise ...
//    exit(EXIT_SUCCESS);
//  }
//---------------------------------------------------------------
// Systemnahme Programmierung SWD21
//
// Susanne Peer

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h> 

int setSignalHandler(int signal, void (*signalhandler)(int)) {
    struct sigaction sa;
    sa.sa_handler = signalhandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(signal, &sa, NULL) == -1) {
        return -1;
    }
    return 0;
}

void sigint_handler(int signum) {
    const char *msg = "SIGINT aufgetreten.\n";
    write(STDOUT_FILENO, msg, strlen(msg));
}

int main(int argc, char* argv[]) {
    if (setSignalHandler(SIGINT, sigint_handler) == -1) {
        perror("Error setting up the signal handler");
        exit(EXIT_FAILURE);
    }
    
    sleep(2);
    
    raise(SIGINT);
    
    exit(EXIT_SUCCESS);
}
