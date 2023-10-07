#include <stdio.h>
#include "include/sum.h"

int main(void) {
    int a = 5, b = 2;

    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));

    return 0;
}