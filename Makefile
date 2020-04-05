prog:entite.o main.o
	gcc entite.o main.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g
entite.o:entite.c
	gcc -c entite.c -lSDL -lSDL_image -g
