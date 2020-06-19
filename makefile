Domino: manage.o utils.o argengine.o
	g++ -g -I/usr/local/include -L/usr/local/lib -o Domino *.o -lyaml-cpp
	@echo "Cleaning Up..."
	rm *.o

manage.o: manage.cpp
	g++ -c -g manage.cpp

utils.o: utils.cpp utils.h
	g++ -c -g utils.cpp

argengine.o: argengine.cpp argengine.hpp
	g++ -c -g argengine.cpp

clean:
	-rm *.o
	-rm ./Domino
