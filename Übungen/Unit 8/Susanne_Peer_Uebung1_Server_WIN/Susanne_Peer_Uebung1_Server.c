//------------------------------------------------------------
// Uebung 1: Server
//
//                          ~Angabe~ 
// Schreiben sie ein Programm server.c, das einen Socket-Server, der 
// auf Port 17000 Verbindungen akzeptiert, implementiert.
//
// Lesen sie den Netzwerkstream einmal mit read() ein und geben sie 
// die empfangenen Zeichen auf stdout aus.
// Nehmen sie für die Größe des Read-Buffers den Wert 256 an.
//
// Nachdem die Daten gelesen wurden, senden sie mit write() folgenden 
// String an den Absender zurück
//    "HTTP/1.1 200 OK\r\n\r\nHallo!\r\n"
// und schließen dann den Socket.
//
// Klammern sie accept(), read() und write() in einer Endlosschleife, so 
// dass neue Verbindungen aufgebaut werden können sobald die Aktuelle beendet ist.
//
// Zum Testen können sie folgenden Befehl verwenden:
//    curl --get http://localhost:17000 
//
//------------------------------------------------------------
// Systemnahme Programmierung SWD21
//
// Susanne Peer, SWD21

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h> // Windows Sockets API!! 

#define PORT 17000
#define BUFFER_SIZE 256

int main() {
    WSADATA wsaData;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Initialize Winsock - Windows Sockets API!!
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("Error initializing Winsock");
        exit(EXIT_FAILURE);
    }
 
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        perror("Error creating socket");
        WSACleanup();
        exit(EXIT_FAILURE);
    }
   
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        perror("Error binding");
        closesocket(server_socket);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == SOCKET_ERROR) {
        perror("Error listening");
        closesocket(server_socket);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == INVALID_SOCKET) {
            perror("Error accepting connection");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
        bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_read == SOCKET_ERROR) {
            perror("Error reading from socket");
            closesocket(client_socket);
            continue;
        } else if (bytes_read == 0) {
            printf("Connection closed by client\n");
            closesocket(client_socket);
            continue;
        }

        printf("Received data from client:\n%s\n", buffer);

        const char *response = "HTTP/1.1 200 OK\r\n\r\nHallo!\r\n";
        if (send(client_socket, response, strlen(response), 0) == SOCKET_ERROR) {
            perror("Error writing to socket");
        }

    
        closesocket(client_socket);
    }

    closesocket(server_socket);

    // Clean up Winsock - Windows Sockets API!! 
    WSACleanup();

    return 0;
}
