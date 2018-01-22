.DEFAULT_GOAL := all

FILES :=                                  \
    .gitignore                            \
    collatz-tests                         \
    Collatz.c++                           \
    Collatz.h                             \
    Collatz.log                           \
    html                                  \
    makefile                              \
    RunCollatz.c++                        \
    RunCollatz.in                         \
    RunCollatz.out                        \
    TestCollatz.c++

# uncomment these three lines when you've created those files
# you must replace GitHubID with your GitHubID
#    .travis.yml                           \
#    collatz-tests/GitHubID-RunCollatz.in  \
#    collatz-tests/GitHubID-RunCollatz.out

collatz-tests:
	git clone https://github.com/cs371pt-spring-2018/collatz-tests.git

html: Doxyfile Collatz.h
	doxygen Doxyfile

Collatz.log:
	git log > Collatz.log

# you must edit Doxyfile and
# set EXTRACT_ALL     to YES
# set EXTRACT_PRIVATE to YES
# set EXTRACT_STATEIC to YES
Doxyfile:
	doxygen -g

RunCollatz: Collatz.h Collatz.c++ RunCollatz.c++
	-clang-check -extra-arg=-std=c++11          Collatz.c++     --
	-clang-check -extra-arg=-std=c++11 -analyze Collatz.c++     --
	-clang-check -extra-arg=-std=c++11          RunCollatz.c++  --
	-clang-check -extra-arg=-std=c++11 -analyze RunCollatz.c++  --
	g++-7 -pedantic -std=c++14 -Wall -Weffc++ -Wextra Collatz.c++ RunCollatz.c++ -o RunCollatz

RunCollatz.c++x: RunCollatz
	./RunCollatz < RunCollatz.in > RunCollatz.tmp
	-diff RunCollatz.tmp RunCollatz.out

TestCollatz: Collatz.h Collatz.c++ TestCollatz.c++
	-clang-check -extra-arg=-std=c++11          TestCollatz.c++ --
	-clang-check -extra-arg=-std=c++11 -analyze TestCollatz.c++ --
	g++-7 -fprofile-arcs -ftest-coverage -pedantic -std=c++14 -Wall -Weffc++ -Wextra Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -pthread

TestCollatz.c++x: TestCollatz
	valgrind ./TestCollatz
	gcov-7 -b Collatz.c++ | grep -A 5 "File '.*Collatz.c++'"

all: RunCollatz TestCollatz

check: $(FILES)

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.plist
	rm -f *.tmp
	rm -f RunCollatz
	rm -f TestCollatz

config:
	git config -l

docker:
	docker run -it -v $(PWD):/usr/collatz -w /usr/collatz gpdowning/gcc

format:
	clang-format -i Collatz.c++
	clang-format -i Collatz.h
	clang-format -i RunCollatz.c++
	clang-format -i TestCollatz.c++

run: RunCollatz.c++x TestCollatz.c++x

scrub:
	make clean
	rm -f  Collatz.log
	rm -f  Doxyfile
	rm -rf collatz-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

travis: collatz-tests html Collatz.log
	make clean
	ls -al
	make
	ls -al
	make run
	ls -al
	make -r check
