#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
    struct sockaddr_in dest_info;
    char *data = "Hello Server. from VM c \n";

    // Create a UDP socket
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set destination address
    memset(&dest_info, 0, sizeof(dest_info));

    dest_info.sin_family = AF_INET;
    dest_info.sin_addr.s_addr = inet_addr("10.9.0.5");
    dest_info.sin_port = htons(9090);

    // Send UDP packet
    if (sendto(sock, data, strlen(data), 0,
               (struct sockaddr *)&dest_info,
               sizeof(dest_info)) < 0) {
        perror("sendto");
        close(sock);
        return 1;
    }

    close(sock);
    return 0;
}
