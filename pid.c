#include "unistd.h"
#include <stdio.h>


int main(void) {
    pid_t pid = getpid();
    printf("pid is %d\n", pid);

    pid_t ppid = getppid();
    printf("ppid is %d\n", ppid);
}