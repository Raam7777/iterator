#!make -f

all: demo
	./$<

demo:  Demo.o
	clang++-5.0 -std=c++17 $^ -o demo

test:  Test.o
	clang++-5.0 -std=c++17 $^ -o test

test2:  Test2.o
	clang++-5.0 -std=c++17 $^ -o test2

%.o: %.cpp range.hpp chain.hpp powerset.hpp product.hpp zip.hpp
	clang++-5.0 -std=c++17 --compile $< -o $@

clean:
	rm -f *.o demo test test2
