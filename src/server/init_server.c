/*
** EPITECH PROJECT, 2022
** EPITECH-WORKSOP-Chat-Box-in-C
** File description:
** init_server
*/

#include "server.h"

server_t *init_server(char *ip_addr, int port)
{
    server_t *server = malloc(sizeof(server_t));
    int sockfd;
    char buf[32];
    struct sockaddr_in addr_server;
    socklen_t addrlen = sizeof(struct sockaddr_in);

    sockfd = socket(AF_INET , SOCK_STREAM , 0);
    if (sockfd == -1)
    {
        perror("Could not create socket");
        return NULL;
    }
    server->ip_addr = ip_addr;
    server->port = port;
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(port);
    addr_server.sin_addr.s_addr = inet_addr(ip_addr);
    bind(sockfd,(struct sockaddr *)&addr_server, sizeof(addr_server));
    listen(sockfd, 1);
    printf("%s\n", ip_addr);
    int fd = accept(sockfd, (struct sockaddr *)&addr_server, &addrlen);
    if (fd == -1) {
        perror("accept()");
        return NULL;
    }
    int len;
    while (1) {
        if((len = recv(fd, buf, sizeof(buf) - 1, 0)) < 0) {
            perror("recv()");
            return NULL;
        }
    }
    buf[len] = '\0';
    write(1, buf, len);
    close(sockfd);
    return server;
}