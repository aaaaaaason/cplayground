#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void *lib = dlopen("bin/libplayground.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!lib) {
        fprintf(stderr, "failed to open lib: %s\n", dlerror());
        exit(1);
    }

    void *fptr = dlsym(lib, "add");
    if (!fptr) {
        fprintf(stderr, "failed to load sym: %s\n", dlerror());
        exit(1);
    }

    int (*fadd)(int, int) = fptr;

    printf("%d + %d = %d\n", 5, 2, fadd(5, 2));

    return 0;
}