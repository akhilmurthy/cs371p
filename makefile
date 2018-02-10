.DEFAULT_GOAL := all

all:
	cd examples; make all
	@echo
	cd projects/collatz; make all

clean:
	cd examples; make clean
	@echo
	cd projects/collatz; make clean

config:
	git config -l

docker:
	docker run -it -v $(PWD):/usr/cs371p -w /usr/cs371p gpdowning/gcc

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:gpdowning/cs371p.git
	git push -u origin master

pull:
	make clean
	@echo
	git pull
	git status

push:
	make clean
	@echo
	git add .gitignore
	git add .travis.yml
	git add examples
	git add makefile
	git add notes
	git add projects/collatz
	git commit -m "another commit"
	git push
	git status

run:
	cd examples; make run
	@echo
	cd projects/collatz; make run

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

sync:
	@rsync -r -t -u -v --delete            \
    --include "Docker.txt"                 \
    --include "Dockerfile"                 \
    --include "Hello.c++"                  \
    --include "Assertions.c++"             \
    --include "UnitTests1.c++"             \
    --include "UnitTests2.c++"             \
    --include "UnitTests3.c++"             \
    --include "Coverage1.c++"              \
    --include "Coverage2.c++"              \
    --include "Coverage3.c++"              \
    --include "IsPrime.c++"                \
    --include "IsPrimeT.c++"               \
    --include "Exceptions.c++"             \
    --include "Incr.c++"                   \
    --include "IncrH.c++"                  \
    --include "IncrT.c++"                  \
    --include "StrCmp.c++"                 \
    --include "StrCmpH.c++"                \
    --include "StrCmpT.c++"                \
    --include "Variables.c++"              \
    --include "Arguments.c++"              \
    --include "Consts.c++"                 \
    --include "Arrays.c++"                 \
    --include "Equal.c++"                  \
    --include "Types.c++"                  \
    --exclude "*"                          \
    ../../examples/c++/ examples
	@rsync -r -t -u -v --delete            \
    --include "Collatz.c++"                \
    --include "Collatz.h"                  \
    --include "RunCollatz.c++"             \
    --include "RunCollatz.in"              \
    --include "RunCollatz.out"             \
    --include "TestCollatz.c++"            \
    --exclude "*"                          \
    ../../projects/c++/collatz/ projects/collatz

travis:
	cd examples; make travis
	@echo
	cd projects/collatz; make travis
