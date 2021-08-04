#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUF_SIZE 100

int main() {
  int sockfd;
  struct sockaddr_in addr_srv;
  const char *tmp = "quit";
  char buffer[BUF_SIZE];
  socklen_t addr_len;

  memset(&addr_srv, 0, sizeof(addr_srv));
	addr_srv.sin_family = AF_INET;
	addr_srv.sin_port = htons(4444);
	addr_srv.sin_addr.s_addr = inet_addr("127.0.0.1");
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  addr_len = sizeof(struct sockaddr_in);
  
  sendto(sockfd, (char *)tmp, strlen(tmp), 0, (const struct sockaddr *)&addr_srv, sizeof(addr_srv));
  recvfrom(sockfd, (char *)buffer, 1024, 0, (struct sockaddr *)&addr_srv, &addr_len);
  printf("%s\n", buffer);
  close(sockfd);
}


