#include <stdio.h>
#include <nanomsg/nn.h>
#include <nanomsg/pubsub.h>

int main(){
    int sock = nn_socket(AF_SP, NN_SUB);
    nn_setsockopt(sock, NN_SUB, NN_SUB_SUBSCRIBE, "", 0);
    int binder = nn_connect(sock,"tcp://127.0.0.1:5560");
    printf("Waiting for broadcast\n");
    for(;;){
        char *buf = NULL;
        nn_recv(sock, &buf, NN_MSG, 0);
        printf("RECEIVED BROADCAST : \"%s\"\n", buf); 
        nn_freemsg(buf);
    }
}