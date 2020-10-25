all: main.o cipherer.o
	$(CC) $(CFLAGS) main.o cipherer.o -o caesar.out

main.o: main.c
	$(CC) $(CFLAGS) main.c -c -o main.o

cipherer.o: cipherer.c
	$(CC) $(CFLAGS) cipherer.c -c -o cipherer.o

clean:
	-rm *.out *.o *.exe

tidy:
	rm *.o
