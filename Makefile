CFLAGS += -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs

optional: src/util/optional.c src/util/optional.h
		gcc $(CFLAGS) -c -o src/util/optional.o src/util/optional.c 

queue: src/ds/queue.c src/ds/queue.h src/util/optional.o
		gcc $(CFLAGS) -o queue.o src/ds/queue.c src/util/optional.o 

