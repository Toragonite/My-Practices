all : main.o
	gcc -g main.o -lncurses

clean:
	rm a.out *.o
