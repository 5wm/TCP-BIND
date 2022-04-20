#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "includes/config.h"

int main(void) {
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(IP);

    int connection = connect(sock, (struct sockaddr *) &server_address, 
    sizeof(server_address));

    char server_response[256];
    recv(sock, &server_response, sizeof(server_response), 0);
    if (connection == -1) {
        printf("ERROR WITH THE CONNECTION!\n");
    }
    else {
        printf("THE SERVER RESPONDED WITH: %s\n" , server_response);
    }
    return EXIT_SUCCESS;
}