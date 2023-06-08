all : main.o
	gcc -g -std=c++11 main.o -I/usr/local/mysql/include -L/usr/local/mysql/lib -lmysqlclient

clean:
	rm a.out *.o
