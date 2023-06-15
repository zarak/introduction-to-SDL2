build:
	g++ -std=c++17 main.cpp -lSDL2 -I./glad/include -o prog

run:
	./prog
