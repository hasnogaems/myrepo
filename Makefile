CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic -ftest-coverage -fprofile-arcs
LIBS = -lm
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

.PHONY: all clean test gcov_report debug

all: s21_math.a test

s21_math.a: s21_math.o
	ar rcs $@ $^

s21_math.o: s21_math.c s21_math.h
	$(CC) $(CFLAGS) -c $< -o $@ 

test: test_s21_math.o s21_math.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@ -lcheck -lm -lpthread -lsubunit

test1: m.o s21_math.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@ -lcheck -lm -lpthread

m.o: m.c s21_math.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

test_s21_math.o: test_s21_math.c s21_math.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

gcov_report: test
	./$^
	gcovr -r . --html --html-details -o gcov_report.html

clean:
	rm -f *.a
	rm -f *.o
	rm -f test
	rm -f test1
	rm -f *.gc*
	rm -f gcov_report.html

rebuild: clean all
	clear

re:clean test1

debug:
	gcc my_functions.c s21_math.c -o debug -lm