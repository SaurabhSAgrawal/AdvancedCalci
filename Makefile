
all: project

project: stack.o
	cc main.c stack.o calculator.o -o project `pkg-config --cflags --libs gtk+-2.0` -lm
stack.o: calculator.o
	cc -c stack.c
calculator.o:
	cc -c calculator.c `pkg-config --cflags --libs gtk+-2.0` 
	
clear: project
	rm -rf *o project
