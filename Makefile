SRC_DIR = ./source
TOOL_DIR = $(SRC_DIR)/tools

all: RunCollatz

Collatz.log:
	git log > Collatz.log

Doxyfile:
	doxygen -g

html: Doxyfile $(SRC_DIR)/Collatz.h $(SRC_DIR)/Collatz.cpp $(SRC_DIR)/main.cpp $(SRC_DIR)/TestCollatz.cpp
	doxygen Doxyfile

RunCollatz: $(SRC_DIR)/Collatz.h $(SRC_DIR)/Collatz.cpp $(SRC_DIR)/main.cpp
	g++ -pedantic -std=c++11 -Wall $(filter %.cpp, $^) -o RunCollatz

RunCollatz.out: RunCollatz RunCollatz.in
	RunCollatz < RunCollatz.in > RunCollatz.tmp

RunCollatz.tmp: RunCollatz RunCollatz.in
	RunCollatz < RunCollatz.in > RunCollatz.tmp
	diff RunCollatz.tmp RunCollatz.out

test: $(SRC_DIR)/Collatz.h $(SRC_DIR)/Collatz.cpp $(SRC_DIR)/UnitTests.cpp
	g++ -pedantic -std=c++11 -Wall $(filter %.cpp, $^) -o test -lgtest -lgtest_main -lpthread

TestCollatz.out: test
	valgrind ./test        >  TestCollatz.out 2>&1
	gcov -b Collatz.cpp     >> TestCollatz.out
	gcov -b UnitTests.cpp >> TestCollatz.out

gen: $(TOOL_DIR)/randomRangeGenerator.cpp
	g++ -pedantic -std=c++11 -Wall $^ -o gen

range: $(TOOL_DIR)/rangeCacheCreator.cpp
	g++ -pedantic -std=c++11 -Wall $^ -o rgen

judge: $(SRC_DIR)/main.cpp $(SRC_DIR)/Collatz.cpp
	@mkdir -p judge
	@cp $(SRC_DIR)/Collatz.cpp ./judge/Collatz.cpp
	@echo "" >> ./judge/Collatz.cpp
	@grep -A500 "int main" $(SRC_DIR)/main.cpp >> ./judge/Collatz.cpp

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunCollatz
	rm -f RunCollatz.out
	rm -f RunCollatz.tmp
	rm -f test
	rm -f TestCollatz.out
	rm -f -r ./judge
	rm -f gen
	rm -f rgen
