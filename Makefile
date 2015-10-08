try: integer.o 
	cc integer.o -o try
integer.o: integer.c
	cc -Wall -c integer.c
