all: work15.o
	gcc -o work15 work15.o

work15.o: work15.c
	gcc -c work15.c

run:
	./work15