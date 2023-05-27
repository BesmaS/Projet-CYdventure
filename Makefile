all: game

save.o: save.c save.h
	gcc -Wall -Wextra -Wpedantic -c save.c

filemanagement.o: filemanagement.c filemanagement.h
	gcc -Wall -Wextra -Wpedantic -c filemanagement.c

menu.o: menu.c menu.h
	gcc -Wall -Wextra -Wpedantic -c menu.c

game : main.c save.o filemanagement.o menu.o
	gcc -Wall -Wextra -Wpedantic main.c save.o filemanagement.o menu.o -o game
