#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>

int main(int argc, char *argv[]){

    struct hostent *host_info;
    struct in_addr *address;

    if(argc < 2 || argc > 2){
        fprintf(stdout,"usage <www.google.com>\n");
        exit(0);
    }else{
    
        host_info=gethostbyname(argv[1]);
        if(host_info == NULL){
            fprintf(stdout,"Could not look up ip addres of %s",argv[1]);
            exit(-1);
        }else{
            address=(struct in_addr*)(host_info->h_addr);
            printf("The %s ip addres is [ %s ]\n",argv[1],inet_ntoa(*address));
        }
    }
    

}
