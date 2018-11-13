#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#define BUFF_SIZE 4
#define EPOLL_SIZE 50
void error_handling(char* buf) {
    fputs(buf, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main(int argc, char* argv[]) {
    int serv_sock, client_sock;
    struct sockaddr_in serv_addr, client_addr;
    socklen_t addr_size;
    int str_len, i;
    char buff[BUFF_SIZE];

    struct epoll_event* ep_events;
    struct epoll_event event;
    int epfd, event_client;

    if (argc != 2) {
        printf("Usage:%s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("bind() error");
    }
    if (listen(serv_sock, 5) == -1) {
        error_handling("listen() error");
    }

    epfd = epoll_create(EPOLL_SIZE);
    ep_events = malloc(sizeof(struct epoll_event)*EPOLL_SIZE);

    event.events = EPOLLIN;
    event.data.fd = serv_sock;
    epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

    while (1) {
        event_client = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        if (event_client == -1) {
            puts("epoll_wait() error");
            break;
        }
        printf("epoll_wait() return\n");
        for (i = 0; i < event_client; i++) {
            if (ep_events[i].data.fd == serv_sock) {
                addr_size = sizeof(client_addr);
                client_sock = accept(serv_sock, (struct sockaddr*)&client_addr, &addr_size);
                event.events = EPOLLIN;
                event.data.fd = client_sock;
                epoll_ctl(epfd, EPOLL_CTL_ADD, client_sock, &event);
                printf("connected client : %d\n", client_sock);
            } else {
                str_len = read(ep_events[i].data.fd, buff, BUFF_SIZE);
                if (str_len == 0) {
                    epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
                    close(ep_events[i].data.fd);
                    printf("closed client: %d\n", ep_events[i].data.fd);
                } else {
                    write(ep_events[i].data.fd, buff, str_len);
                }
            }
        }
    }
    close(serv_sock);
    close(epfd);
    free(ep_events);
    return 0;
}









