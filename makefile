main: funkcijos.o
	g++ -o3 main main-vectors.cpp funkcijos.o
funkcijos:
	g++ -c funkcijos.cpp
clean:
	rm *.o main