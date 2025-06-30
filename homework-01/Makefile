make: clean build run
clean:
	rm -f *.x
build: main.cpp clean
	g++ --std=c++20 -o app.x main.cpp
run: app.x
	./app.x
