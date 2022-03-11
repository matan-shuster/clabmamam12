all:magic

magic:magic.o
	gcc -Wall -ansi -pedantic -Wpedantic -Werror -g magic.c -o magic

magic.o:magic.c
	gcc -c magic.c -o magic.o

clean :
	rm -f magic.o magic.exe
exec:
	./'maman 12'
