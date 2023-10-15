#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include "sys/signal.h"

void sigint_handler(int s) {
    printf("receive signal: %d\n", s);
}

int main(void) {
    struct sigaction act;
    act.sa_handler = sigint_handler;

    printf("pid = %d\n", getpid());
    sigaction(SIGINT, &act, NULL);

    printf("start sleeping\n");
    
    int secs = 10;
    while ((secs = sleep(secs)) > 0) {
        printf("%d secs remaining\n", secs);
    }

    printf("done\n");
    exit(0);
}