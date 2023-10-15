#include "unistd.h"
#include "sys/types.h"
#include "sys/wait.h"
#include <stdio.h>
#include <stdlib.h>

void check_wait_status(int ws);

int main() {
    pid_t id;
    pid_t wait_pid;

    if ((id = fork()) < 0) {
        perror("fork process");
    } else if (id > 0) {
        printf("this is parent with pid = %d\n", getpid());
        printf("child pid = %d\n", id);
    } else {
        printf("child starts sleeping\n");
        sleep(4);
        exit(0);
    }

    int wait_status;
    if ((wait_pid = wait(&wait_status)) < 0) {
        perror("wait child exit");
    }

    check_wait_status(wait_status);

    printf("child %d done\n", wait_pid);
    return 0;
}

void check_wait_status(int ws) {
    if (WIFEXITED(ws)) {
        printf("terminated normally: %d\n", WEXITSTATUS(ws));
    } else if (WIFSIGNALED(ws)) {
        printf("terminated by signal %d\n", WTERMSIG(ws));
    }
}