#include <stdio.h>
#include <nanomsg/nn.h>
#include <nanomsg/pipeline.h>

int main(){
    int sock = nn_socket(AF_SP, NN_PULL);
    int binder = nn_bind(sock,"tcp://127.0.0.1:5560");
    for(;;){
        char *buf = NULL;
        nn_recv(sock, &buf, NN_MSG, 0);
        printf("Receiver: RECEIVED \"%s\"\n", buf); 
        nn_freemsg(buf);
    }
}