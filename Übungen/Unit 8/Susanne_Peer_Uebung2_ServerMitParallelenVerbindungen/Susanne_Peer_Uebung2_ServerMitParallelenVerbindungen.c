//----------------------------------------------
// Uebung 2: server mit parallelen Verbindungen
// Erweitern sie ihren Server so, dass er mehrere Verbindungen gleichzeitig aufbauen und bearbeiten kann.
// Verwenden sie fork() um die akzeptierte Verbindung in einem Kindprozess abzuarbeiten.
//
// Installieren sie einen Signalhandler für das Signal SIGCHLD und warten sie im Signalhandler auf den Kindprozess. Geben sie in diesem Signalhandler die Meldung "Waited for child" aus, damit sichtbar wird, wann der Prozess beendet wurde.
// Ignorieren sie das Signal SIGPIPE, damit, wenn ein Client beendet wird, nicht der Serverprozess terminiert wird.
//
//Setzen sie für den Server-Socket die Socket-Optionen SO_REUSEADDR und SO_KEEPALIVE.
//
//Geben nach jedem fork() die IP Adresse des Clients (inet_ntop) und die PID des neu erzeugten Child-Prozesses in folgender Form aus:
//    Started new process 23014 for client: 127.0.0.1
//
//Testen
//Um mehrere Verbindungen zu testen, bauen sie (in einem separaten Terminal) eine zusätzliche Verbindung zum Server mit telnet auf
//
//    telnet localhost 17000
//
//und lassen diese Verbindung so stehen.
//
//Testen sie nun wie gehabt mit curl ob mehrere Verbindungen gleichzeitig möglich sind.
//-------------------------------------------------
// Systemnahe Programmierung
//
// Susanne Peer SWD21

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>

#define PORT 17000

void sigchld_handler(int sig) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
    printf("Waited for child\n");
}

int main() {
    printf("Server auf Port %d gestartet. Warte auf Verbindungen...\n", PORT);

    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;
    int clientAddrLen = sizeof(clientaddr);
    int sockfd, newsockfd;
    char buffer[256];

    signal(SIGCHLD, sigchld_handler); 

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)); 
    setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof(optval)); 

    memset((char *)&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, (socklen_t *)&clientAddrLen);
        if (newsockfd == -1) {
            perror("Accept failed");
            continue;
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("Fork failed");
            close(newsockfd);
            continue;
        } else if (pid == 0) {
            close(sockfd);

            char ipstr[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(clientaddr.sin_addr), ipstr, INET_ADDRSTRLEN);
            printf("Started new process %d for client: %s\n", getpid(), ipstr);

            int bytes_read = read(newsockfd, buffer, sizeof(buffer));
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                printf("Received: %s\n", buffer);
            }

            char *response = "HTTP/1.1 200 OK\r\n\r\nHallo!\r\n";
            write(newsockfd, response, strlen(response));

            close(newsockfd);
            exit(EXIT_SUCCESS); 
        } else {
            close(newsockfd);
        }
    }

    return 0;
}
