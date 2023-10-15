OUT = bin
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
AR = ar
ARFLAGS = -rcs
LDFLAGS = -lplayground
INCLUDES = -Iinclude
LIB_FILES = sum.o
LD_LIBRARY_PATH = -L$(OUT)

%: outdir %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LD_LIBRARY_PATH) $(LDFLAGS) $@.c -o $(OUT)/$*

.c.o:
	$(CC) -c $(CFLAGS) $< -o $(OUT)/$@

outdir:
	mkdir -p bin

libplayground: $(LIB_FILES)
	@cd $(OUT); $(AR) $(ARFLAGS) libplayground.a $(LIB_FILES)

soplayground: $(LIB_FILES)
	cd $(OUT); $(CC) -shared $(CCFLAGS) $(LIB_FILES) -o libplayground.so

shared: shared.o
	$(CC) $(CFLAGS) $(INCLUDES) $@.c -o $(OUT)/$@

.PHONY: clean
clean:
	@rm -rf bin/*