prog:boundingBox.o main.o
	gcc boundingBox.o main.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g
boundingBox.o:boundingBox.c
	gcc -c boundingBox.c -lSDL -lSDL_image -g
