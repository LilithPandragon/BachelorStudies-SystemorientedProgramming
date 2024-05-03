//--------------------------------------------------------
//
// Ubung 1 : Server
// Schreiben sie ein Programm server.c, das einen Socket-Server, 
// der auf Port 17000 Verbindungen akzeptiert, implementiert.
//
// Lesen sie den Netzwerkstream einmal mit read() ein und geben 
// sie die empfangenen Zeichen auf stdout aus.
// Nehmen sie für die Größe des Read-Buffers den Wert 256 an.
//
// Nachdem die Daten gelesen wurden, senden sie mit write() folgenden String 
// an den Absender zurück
//    "HTTP/1.1 200 OK\r\n\r\nHallo!\r\n"
// und schließen dann den Socket.
//
// Klammern sie accept(), read() und write() in einer Endlosschleife, so 
// dass neue Verbindungen aufgebaut werden können sobald die Aktuelle beendet ist.
//
// Zum Testen können sie folgenden Befehl verwenden:
//    curl --get http://localhost:17000
// -----------------------------------------------------------
// Systemnahe Programmierung SWD21
//
// Susanne Peer, SWD21


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("Server wird auf Port 17000 gestartet. Warte auf Verbindungen...\n");

    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;
    int clientAddrLen = sizeof(clientaddr);
    int sockfd, newsockfd;
    char buffer[256];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset((char *)&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(17000);

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

        int bytes_read = read(newsockfd, buffer, sizeof(buffer));
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("Received: %s\n", buffer);
        }

        char *response = "HTTP/1.1 200 OK\r\n\r\nHallo!\r\n";
        write(newsockfd, response, strlen(response));

        close(newsockfd);
    }

    return 0;
}
