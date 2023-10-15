#include "unistd.h"
#include "sys/types.h"
#include <stdio.h>

int main() {
    uid_t uid = getuid();
    printf("uid is %d\n", uid);

    uid_t gid = getgid();
    printf("gid is %d\n", gid);

    uid_t euid = geteuid();
    printf("euid is %d\n", euid);

    uid_t egid = getegid();
    printf("egid is %d\n", egid);
}