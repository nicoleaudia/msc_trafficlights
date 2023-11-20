traffic: time.o trafficLight.o main.o
	g++ -g -Wall main.o trafficLight.o time.o -o traffic

time.o: time.cpp time.h
	g++ -g -Wall -c time.cpp -o time.o

trafficLight.o: trafficLight.cpp trafficLight.h time.h
	g++ -g -Wall -c trafficLight.cpp -o trafficLight.o

main.o: main.cpp time.h trafficLight.h
	g++ -g -Wall -c main.cpp -o main.o

clean:
	rm -f traffic *.o
