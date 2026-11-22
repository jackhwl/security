#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t clientlen;
    char buf[1500];

    // Create UDP socket
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Configure server address
    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(9090);

    // Bind socket
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        close(sock);
        return 1;
    }

    printf("UDP Server listening on port 9090...\n");

    while (1) {
        memset(buf, 0, sizeof(buf));
        clientlen = sizeof(client);

        ssize_t n = recvfrom(sock, buf, sizeof(buf) - 1, 0,
                             (struct sockaddr *)&client,
                             &clientlen);

        if (n < 0) {
            perror("recvfrom");
            continue;
        }

        buf[n] = '\0';

        printf("Sender: %s:%u\n",
               inet_ntoa(client.sin_addr),
               (unsigned)ntohs(client.sin_port));

        printf("Received: %s\n", buf);
    }

    close(sock);
    return 0;
}