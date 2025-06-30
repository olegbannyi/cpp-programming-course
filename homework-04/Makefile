make: clean build run
run:
	./cpp-pro-xw-4.x
build: clean main.o math.o order.o order-processor.o
	g++ -std=c++20 main.o math.o order.o order-processor.o -o cpp-pro-xw-4.x
main.o: main.cpp
	g++ -std=c++20 -c main.cpp
math.o: math.cpp
	g++ -std=c++20 -c math.cpp
order.o: order.cpp
	g++ -std=c++20 -c order.cpp
order-processor.o: order-processor.cpp
	g++ -std=c++20 -c order-processor.cpp
clean:
	rm -f *.o *.x