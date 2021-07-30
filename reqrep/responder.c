#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<nanomsg/nn.h>
#include<nanomsg/reqrep.h>

int main(){
    char *buf = NULL;
    int sock = nn_socket(AF_SP, NN_REP);
    int binder = nn_bind(sock,"tcp://127.0.0.1:5560");
    for(;;){
        nn_recv(sock, &buf, NN_MSG, 0);
        printf("responder: received \"%s\", will proceed to respond\n", buf); 
        char *msg;
        msg = (char *) malloc(sizeof(char) * (strlen(buf) + 20)); 
        sprintf(msg,"Okay i received : %s\n", buf);
        nn_send(sock, msg, strlen(msg), 0);
        nn_freemsg(buf);

    }
    
}