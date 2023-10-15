#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "sys/time.h"

int main(void) {
    time_t now = time(NULL);
    printf("now in time_t: %ld\n", now);

    struct tm now_tm;
    localtime_r(&now, &now_tm);

    char buf[50] = {0};
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &now_tm);
    printf("stftime %s\n", buf);


    struct timeval tv;
    int ret;
    if ((ret = gettimeofday(&tv, NULL)) < 0) {
        perror("gettimeofday");
        exit(1);
    }

    printf("sec: %ld, usec: %ld\n", tv.tv_sec, tv.tv_usec);

    return 0;
}