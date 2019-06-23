# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
#Makefile для 26 лабы
CC=gcc
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall

all: hello

hello: main.o deque.o sort.o
	$(CC) main.o deque.o sort.o -o hello

main.o: main.c
	$(CC) $(CFLAGS) main.c

deque.o: deque.c
	$(CC) $(CFLAGS) deque.c

sort.o: sort.c
	$(CC) $(CFLAGS) sort.c

clean:
	rm -rf *.o hello 
