main: funkcijos.o
	g++ -o3 -o main -main.cpp funkcijos.o
funkcijos:
	g++ -c funkcijos.cpp
clean:
	rm *.o main