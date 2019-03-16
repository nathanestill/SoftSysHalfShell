parse: parse.o listrem.o init.o direct.o
	gcc parse.o listrem.o init.o direct.o -o parse

parse.o: parse.c switch.h
	gcc -c parse.c

listrem.o: listrem.c
	gcc -c listrem.c

init.o: init.c
	gcc -c init.c

direct.o: direct.c
	gcc -c direct.c