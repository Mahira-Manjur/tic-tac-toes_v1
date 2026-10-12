

CC      = gcc
CFLAGS  = -std=c99 -Wall -O2
LDLIBS  = -lraylib -lopengl32 -lgdi32 -lwinmm -lm

v1: $(wildcard tttv1_console/*.c)
	$(CC) $(CFLAGS) $^ -o v1

v2: $(wildcard tttv2_graphics/*.c)
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o v2

run1: v1
	./v1
run2: v2
	./v2

clean:
	rm -f v1 v1.exe v2 v2.exe

.PHONY: run1 run2 clean