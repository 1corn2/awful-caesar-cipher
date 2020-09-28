base: caesar.o
	$(CC) $(CFLAGS) caesar.o -o caesar.out

caesar.o: caesar.c
	$(CC) $(CFLAGS) caesar.c -c -o caesar.o

clean:
	rm *.out *.o
