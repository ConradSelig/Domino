Domino: manage.o utils.o yaml_extension.o argengine.o
	g++ -g -I/usr/local/include -L/usr/local/lib -o Domino *.o -lyaml-cpp
	@echo "Cleaning Up..."
	rm *.o

manage.o: manage.cpp
	g++ -c -g manage.cpp

utils.o: utils.cpp utils.h
	g++ -c -g utils.cpp

argengine.o: argengine.cpp argengine.hpp
	g++ -c -g argengine.cpp

yaml_extension.o: yaml_extension.cpp yaml_extension.h
	g++ -c -g yaml_extension.cpp

clean:
	-rm ./Domino
