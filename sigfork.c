#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include "sys/types.h"
#include "sys/signal.h"

void sigint_handler(int s) {
    printf("receive signal: %d %d\n", s, getpid());
}

void sleep_awhile(pid_t pid, int secs) {
    printf("start sleeping, %d\n", pid);
    
    while ((secs = sleep(secs)) > 0) {
        printf("%d secs remaining\n", secs);
    }
    
    printf("done, %d\n", pid);
}

int main(void) {
    struct sigaction act;
    act.sa_handler = sigint_handler;
    sigaction(SIGINT, &act, NULL);

    pid_t id;
    if ((id = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (id > 0) {
        sigset_t set;
        sigfillset(&set);
        sigprocmask(SIG_SETMASK, &set, NULL);
    }

    // all processes receives signals, mask parant's sigset
    sleep_awhile(getpid(), 15);

    exit(0);
}