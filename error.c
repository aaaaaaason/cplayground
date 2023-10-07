#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *fp = fopen("nonexist", "rw");
    if (!fp) {
        perror("cannot open file");
        exit(1);
    }

    fclose(fp);
    return 0;
}