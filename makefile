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
	git add projects/allocator
	git add projects/darwin
	git add projects/life
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
    --include "Arrays1.c++"                \
    --include "Equal.c++"                  \
    --include "EqualT.c++"                 \
    --include "Copy.c++"                   \
    --include "CopyT.c++"                  \
    --include "Fill.c++"                   \
    --include "FillT.c++"                  \
    --include "Iterators.c++"              \
    --include "Factorial.c++"              \
    --include "FactorialT.c++"             \
    --include "RangeIterator.c++"          \
    --include "RangeIteratorT.c++"         \
    --include "Accumulate.c++"             \
    --include "AccumulateT.c++"            \
    --include "Range.c++"                  \
    --include "RangeT.c++"                 \
    --include "Transform.c++"              \
    --include "TransformT.c++"             \
    --include "Functions.c++"              \
    --include "Arrays2.c++"                \
    --include "Vector1.c++"                \
    --include "Vector1T.c++"               \
    --include "Vector2.c++"                \
    --include "Vector2T.c++"               \
    --include "FunctionOverloading.c++"    \
    --include "Move.c++"                   \
    --include "Vector3.c++"                \
    --include "Vector3T.c++"               \
    --include "Memory.h"                   \
    --include "Vector4.c++"                \
    --include "Vector4T.c++"               \
    --include "Types.c++"                  \
    --include "Shapes1.c++"                \
    --exclude "*"                          \
    ../../examples/c++/ examples
	@rsync -r -t -u -v --delete            \
    --include "Darwin.uml"                 \
    --include "Darwin.png"                 \
    --include "Stack1.uml"                 \
    --include "Stack1.png"                 \
    --include "Stack2.uml"                 \
    --include "Stack2.png"                 \
    --include "LifeCC.uml"                 \
    --include "LifeCC.png"                 \
    --include "LifeFC.uml"                 \
    --include "LifeFC.png"                 \
    --include "LifeC.uml"                  \
    --include "LifeC.png"                  \
    --include "Shapes1.uml"                \
    --include "Shapes1.png"                \
    --include "Shapes2.uml"                \
    --include "Shapes2.png"                \
    --exclude "*"                          \
    ../../examples/uml/ examples
	@rsync -r -t -u -v --delete            \
    --include "Collatz.c++"                \
    --include "Collatz.h"                  \
    --include "RunCollatz.c++"             \
    --include "RunCollatz.in"              \
    --include "RunCollatz.out"             \
    --include "TestCollatz.c++"            \
    --exclude "*"                          \
    ../../projects/c++/collatz/ projects/collatz
	@rsync -r -t -u -v --delete            \
    --include "Allocator.h"                \
    --include "RunAllocator.c++"           \
    --include "RunAllocator.in"            \
    --include "RunAllocator.out"           \
    --include "TestAllocator.c++"          \
    --exclude "*"                          \
    ../../projects/c++/allocator/ projects/allocator
	@rsync -r -t -u -v --delete            \
    --include "RunDarwin.c++"              \
    --include "RunDarwin.in"               \
    --include "RunDarwin.out"              \
    --exclude "*"                          \
    ../../projects/c++/darwin/ projects/darwin
	@rsync -r -t -u -v --delete            \
    --include "RunLifeConway.in"           \
    --include "RunLifeConway.out"          \
    --include "RunLifeFredkin.in"          \
    --include "RunLifeFredkin.out"         \
    --include "RunLifeCell.in"             \
    --include "RunLifeCell.out"            \
    --exclude "*"                          \
    ../../projects/c++/life/ projects/life

travis:
	cd examples; make travis
	@echo
	cd projects/collatz; make travis
