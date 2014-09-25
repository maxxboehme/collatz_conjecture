all: RunCollatz

Collatz.log:
	git log > Collatz.log

Doxyfile:
	doxygen -g

html: Doxyfile Collatz.h Collatz.cpp main.cpp TestCollatz.cpp
	doxygen Doxyfile

RunCollatz: Collatz.h Collatz.cpp main.cpp
	g++ -pedantic -std=c++11 -Wall Collatz.cpp main.cpp -o RunCollatz

RunCollatz.out: RunCollatz RunCollatz.in
	RunCollatz < RunCollatz.in > RunCollatz.tmp

RunCollatz.tmp: RunCollatz RunCollatz.in
	RunCollatz < RunCollatz.in > RunCollatz.tmp
	diff RunCollatz.tmp RunCollatz.out

test: Collatz.h Collatz.cpp UnitTests.cpp
	g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.cpp UnitTests.cpp -o test -lgtest -lgtest_main -lpthread

TestCollatz.out: test
	valgrind ./test        >  TestCollatz.out 2>&1
	gcov -b Collatz.cpp     >> TestCollatz.out
	gcov -b UnitTests.cpp >> TestCollatz.out

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunCollatz
	rm -f RunCollatz.out
	rm -f RunCollatz.tmp
	rm -f test
	rm -f TestCollatz.out
