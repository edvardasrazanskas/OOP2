main: funkcijos.o
	g++ -o3 -o main main.cpp studentas.o
funkcijos:
	g++ -c studentas.cpp
clean:
	del *.o main.exe