#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <nanomsg/nn.h>
#include <nanomsg/pubsub.h>

int main(){
    char *msg ;
    msg = (char *) malloc(sizeof(char) * 35); 
    int age = 0;
    int sock = nn_socket(AF_SP, NN_PUB);
    int connect = nn_bind(sock,"tcp://127.0.0.1:5560");
    for(;;){
        sprintf(msg,"Sowon is now %d years old", age);
        nn_send(sock, msg, strlen(msg), 0);
        printf("Broadcasted : \"%s\"\n", msg); 
        age++;
        sleep(1);
    }
    nn_shutdown(sock, 0);
}