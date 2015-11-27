main: main.o MazeVertex.o MazeGraph.o
	g++ -o main main.o MazeVertex.o MazeGraph.o

main.o: main.cpp
	g++ -c main.cpp

MazeVertex.o: MazeVertex.cpp
	g++ -c MazeVertex.cpp

MazeGraph.o: MazeGraph.cpp
	g++ -c MazeGraph.cpp

clean: 
	rm *.o