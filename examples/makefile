.DEFAULT_GOAL := all

FILES :=                    \
    Hello                   \
    UnitTests3              \
    Coverage1               \
    Coverage2               \
    Coverage3               \
    IsPrime                 \
    IsPrimeT                \
    Exceptions              \
    StrCmp

%: %.c++
	-clang-check -extra-arg=-std=c++11          $< --
	-clang-check -extra-arg=-std=c++11 -analyze $< --
	g++-7 -fprofile-arcs -ftest-coverage -pedantic -std=c++14 -Wall -Weffc++ -Wextra $< -o $@ -lgtest -lgtest_main -pthread

%.c++x: %
	valgrind ./$<
	gcov-7 -b $<.c++ | grep -A 5 "File '$<.c++'"

all: $(FILES)

clean:
	rm -f *.bin
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.plist
	rm -f $(FILES)

run: $(FILES:=.c++x)

travis:
	make clean
	ls -al
	make
	ls -al
	make run
	ls -al
