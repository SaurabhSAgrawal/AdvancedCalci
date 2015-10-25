
all: 
	gcc main.c calculator.c stack.c -o project `pkg-config --cflags --libs gtk+-2.0` -lm
