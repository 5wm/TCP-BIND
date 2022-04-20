#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1337 

int main(void) {
    char server_message[256] = "Hello, World! (CTRL + C)";
    int server_sock;
    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr*) &server_address, 
    sizeof(server_address));

    listen(server_sock, 5);

    int client_socket;

    client_socket = accept(server_sock, NULL, NULL);
    
    send(client_socket, server_message, sizeof(server_message), 0);
    close(server_sock);
    return EXIT_SUCCESS;
}