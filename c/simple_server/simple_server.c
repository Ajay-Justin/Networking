#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include"hacking.h"

#define PORT 8080

int main(void){
    int socketfd,newfd;
    struct sockaddr_in host_addr,client_addr;
    socklen_t sin_size;
    int recvlenth=1,yes=1;
    char buffer[1024];

    if((socketfd=socket(PF_INET,SOCK_STREAM,0))==-1){
        fprintf(stdout,"ERROR in socket creation\n");
        exit(-1);
    }
    if(setsockopt(socketfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))==-1){
        fprintf(stdout,"ERROR in setsockopt \n");
        exit(-1);
    }
    host_addr.sin_family=AF_INET;
    host_addr.sin_port=ntohs(PORT);
    host_addr.sin_addr.s_addr=0;
    memset(&(host_addr.sin_zero),'\0',8);

    if(bind(socketfd,(struct sockaddr*)&host_addr,sizeof(struct sockaddr))==-1){
        fprintf(stdout,"ERROR in bind");
        exit(-1);
    }
    if(listen(socketfd,5)==-1){
        fprintf(stdout,"ERROR in listen\n");
        exit(-1);
    }

    while(1){
        sin_size=sizeof(struct sockaddr_in);
        newfd=accept(socketfd,(struct sockaddr*)&client_addr,&sin_size);
        if(newfd == -1){
            fprintf(stdout,"ERROR in accepting connection");
            exit(-1);
        }
        printf("server: Got connection form %s port %d\n",inet_ntoa(client_addr.sin_addr),htons(client_addr.sin_port));
        send(newfd,"This server estamblish by H3ckr basic server and faster\r\n",57,0);
        recvlenth=recv(newfd,&buffer,1024,0);
        while(recvlenth > 0){
            printf("Recived length : %d\n",recvlenth);
            dump(buffer,recvlenth);
            recvlenth=recv(newfd,&buffer,1024,0);
        }
        close(newfd);
    }
}
