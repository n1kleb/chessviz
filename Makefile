all: bin/chessviz

bin/chessviz: build/main.o build/board.o build/board_print_plain.o
	gcc -Wall -Werror build/main.o build/board.o build/board_print_plain.o -o bin/chessviz -lm

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/board.o: src/board.c
	gcc -Wall -Werror -c src/board.c -o build/board.o

build/board_print_plain.o: src/board_print_plain.c
	gcc -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o

clean:
	rm -rf build/*.o bin/chessviz bin/*.o *.o