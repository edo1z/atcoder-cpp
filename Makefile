all: compile run

compile:
	g++ a.cpp -o a.out

run:
	./a.out
