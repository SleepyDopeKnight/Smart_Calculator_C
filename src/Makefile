.PHONY: all tests rebuild open gcov_report install uninstall dist clean check
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
LINUX=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck
LFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

all: SmartCalc.a tests gcov_report dvi check

SmartCalc.a:
	$(CC) $(CFLAGS) -c SmartCalc.c
	ar rcs SmartCalc.a SmartCalc.o
	ranlib SmartCalc.a

tests:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) SmartCalc_tests.c SmartCalc.a -o test.out $(LIBS)
else
	$(CC) $(CFLAGS) SmartCalc_tests.c SmartCalc.a -o test.out $(LIBS) $(LINUX)
endif
	./test.out

dvi:
ifeq ($(OS), Darwin)
	open ReadMe.txt
else
	xdg-open ReadMe.txt
endif

dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src/
	cp -r ./build/Smart_Calculator.app Archive_SmartCalc_v1.0/src/
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	rm -rf Archive_SmartCalc_v1.0/

install:
	mkdir build
	cd SmartCalcQT && qmake && make && make clean && rm Makefile && cd ../
ifeq ($(OS), Darwin)
	mv SmartCalcQT/Smart_Calculator.app build
else
	mv SmartCalcQT/Smart_Calculator build
endif

uninstall:
	rm -rf build*

check:
	clang-format -n -style=google *.c *.h
	cppcheck *.c
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test.out
else
	valgrind ./test.out --leak-check=full
endif

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) SmartCalc_tests.c SmartCalc.c -o test.out $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) SmartCalc_tests.c SmartCalc.c -o test.out $(LIBS) $(LINUX)
endif
	./test.out
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
ifeq ($(OS), Darwin)
	open report/index.html
else
	xdg-open report/index.html
endif

clean:
	rm -rf *.o *.a *.info test.out gcov_test 
	rm -rf report
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf Archive_SmartCalc_v1.0/
	rm -rf *.tgz
	rm -rf build
	rm -rf SmartCalcQT/.qmake.stash

rebuild: clean all
