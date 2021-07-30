#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <nanomsg/nn.h>
#include <nanomsg/pipeline.h>

int main(){
    int sock = nn_socket(AF_SP, NN_PUSH);
    int connect = nn_connect(sock,"tcp://127.0.0.1:5560");
    char *msg ;
    msg = (char *) malloc(sizeof(char) * 7); 
    scanf("%s",msg);
    nn_send(sock, msg, strlen(msg), 0);
    printf("Sender: Sent \"%s\"\n", msg); 
    sleep(1);
    nn_shutdown(sock, 0);
    return 0;
}