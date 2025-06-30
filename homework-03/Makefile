make: clean build run
run: app.x
	./app.x
build: clean main.cpp
	g++ --std=c++20 -o app.x main.cpp
clean:
	rm -f *.x