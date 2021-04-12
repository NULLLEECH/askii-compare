# hardcoded non-dynamic

all:
	cc main.c -o main.o -c -Ofast --std=c99
	cc main.o -o av -Ofast -D NDEBUG --std=c99
clean:
	rm -f *.o av
