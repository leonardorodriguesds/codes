#include <stdio.h>
#include <unistd.h>

void sleepMessage(char message[]) {
    sleep(5);
    printf("%s\n", message);
}

int main(){

    // C
    int i, j, z;
    i = 1, j = 2, z = 3;

    sleepMessage("Mensagem printada...");
    return 0;
}