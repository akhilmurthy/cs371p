.DEFAULT_GOAL := all

all:
	cd examples; make all

clean:
	cd examples; make clean

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
	git commit -m "another commit"
	git push
	git status

run:
	cd examples; make run

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
    --exclude "*"                          \
    ../../examples/c++/ examples
	@rsync -r -t -u -v --delete            \
    --include "Collatz.c++"                \
    --include "Collatz.h"                  \
    --include "RunCollatz.c++"             \
    --include "RunCollatz.in"              \
    --include "RunCollatz.out"             \
    --include "TestCollatz.c++"            \
    --include "TestCollatz.out"            \
    --exclude "*"                          \
    ../../projects/c++/collatz/ projects/collatz

travis:
	cd examples; make travis
