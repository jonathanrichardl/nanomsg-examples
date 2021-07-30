#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<nanomsg/nn.h>
#include<nanomsg/reqrep.h>

int main(){
    char *buf = NULL;
    int sock = nn_socket(AF_SP, NN_REQ);
    int binder = nn_connect(sock,"tcp://127.0.0.1:5560");
    char *msg ;
    msg = (char *) malloc(sizeof(char) * 12); 
    printf("Enter your message : ");
    scanf("%s",msg);
    nn_send(sock, msg, strlen(msg), 0);
    printf("Sender: Sent \"%s\"\n", msg); 
    nn_recv(sock, &buf, NN_MSG, 0);
    printf("Responder says : %s\n", buf);
    nn_freemsg(buf);
    return 0;

}