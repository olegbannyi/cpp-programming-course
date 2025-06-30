make: clean build run
build: main.cpp clean
	g++ --std=c++20 -o app.x main.cpp
clean:
	rm -f *.x
run: app.x
	./app.x