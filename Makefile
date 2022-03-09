CXX_FLAG = --std=c++11 -g

all: tests
tests: heap.o examheap.o
	g++ $(CXX_FLAG) -o tests heap.o examheap.o

heap.o: heap.cpp
	g++ -c $(CXX_FLAG) heap.cpp

examheap.o: examheap.cpp
	g++ -c $(CXX_FLAG) examheap.cpp

clean:
	rm -f main main *.o tests