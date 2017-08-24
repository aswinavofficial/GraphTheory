graph: graph.cpp
	g++ -g -c graph.cpp
test: BitMapMatrix_Test.cpp Main_TestAll.cpp
	g++ -g graph.o BitMapMatrix_Test.cpp Main_TestAll.cpp -lgtest -lpthread -I. -L.
clean:
	rm *.o
