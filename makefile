main: funkcijos.o
	g++ -o3 -o main main-vectors.cpp funkcijos.o
funkcijos:
	g++ -c funkcijos.cpp
clean:
	del *.o main.exe