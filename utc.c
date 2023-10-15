#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "sys/time.h"

int main(void) {
    struct timeval tv;
    int ret;
    if ((ret = gettimeofday(&tv, NULL)) < 0) {
        perror("gettimeofday");
        exit(1);
    }

    struct tm t;
    gmtime_r(&tv.tv_sec, &t);

    char buf[50] = {0};
    size_t l = strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%S", &t);

    snprintf(&buf[l], sizeof(buf)-l, ".%06ldZ", tv.tv_usec);

    printf("time: %s\n", buf);

    return 0;
}