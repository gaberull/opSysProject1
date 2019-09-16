all: project1 storage

project1.o: project1.c 
	gcc -c project1.c  

project1: project1.o
	gcc project1.o -o project1

storage.o: storage.c storage.h
	gcc -c storage.c

storage: storage.o
	gcc storage.o -o storage

clean:
	rm -f *.o project1




