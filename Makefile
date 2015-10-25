all: project

project: stack.o
	cc -Wall main.c stack.o calculator.o -o project `pkg-config --cflags --libs gtk+-2.0` -lm
stack.o: calculator.o
	cc -c -Wall stack.c
calculator.o:
	cc -c -Wall calculator.c `pkg-config --cflags --libs gtk+-2.0` 
	
clear: project
	rm -rf *o project
