all: bin/chessviz bin/chessviz-test format

bin/chessviz: build/src/main.o build/src/board.o build/src/board_print_plain.o
	gcc -Wall -Werror build/src/main.o build/src/board.o build/src/board_print_plain.o -o bin/chessviz -lm

build/src/main.o: src/main.c
	gcc -Wall -Werror -I src -c src/main.c -o build/src/main.o

build/src/board.o: src/board.c
	gcc -Wall -Werror -I src -c src/board.c -o build/src/board.o

build/src/board_print_plain.o: src/board_print_plain.c
	gcc -Wall -Werror -I src -c src/board_print_plain.c -o build/src/board_print_plain.o

format: src/board.c src/board.h src/board_print_plain.c src/board_print_plain.h src/main.c
	clang-format -i src/main.c src/board_print_plain.c src/board.c src/board.h src/board_print_plain.h test/board_test.c test/main.c

bin/chessviz-test: build/test/main.o build/test/board_test.o
	gcc -Wall -Werror build/test/main.o build/test/board_test.o build/src/board_print_plain.o build/src/board.o -o bin/chessviz-test -lm

build/test/main.o: thirdparty/ctest.h
	gcc -I thirdparty -c test/main.c -o build/test/main.o

build/test/board_test.o: src/board.h thirdparty/ctest.h src/board_print_plain.h
	gcc -I thirdparty -I src -c test/board_test.c -o build/test/board_test.o

testRun:
	./bin/chessviz-test

clean:
	rm -rf build/test/board_test.o bin/chessviz bin/chessviz-test build/src/board.o build/src/main.o build/src/board_print_plain.o build/test/main.o

.PHONY: all clean