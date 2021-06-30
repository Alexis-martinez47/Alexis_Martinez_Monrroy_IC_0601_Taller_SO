all:
	gcc -g -c -Wall main.c -pthread -o main.o
	gcc -g -c -Wall scheduler.c -pthread -o scheduler.o
	gcc -g -Wall main.o scheduler.o -pthread -o application

clean:
	rm *.o
	rm application

