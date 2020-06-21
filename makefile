Domino: manage.o utils.o yaml_extension.o argengine.o db_utils.o
	g++-8 -g -std=c++17 -I/usr/local/include -L/usr/local/lib -o Domino *.o -lyaml-cpp -lstdc++fs
	@echo "Cleaning Up..."
	rm *.o

manage.o: manage.cpp
	g++-8 -c -g manage.cpp

argengine.o: argengine.cpp argengine.hpp
	g++-8 -c -g argengine.cpp

utils.o: utils.cpp utils.h
	g++-8 -c -g utils.cpp

yaml_extension.o: yaml_extension.cpp yaml_extension.h
	g++-8 -c -g yaml_extension.cpp

db_utils.o: db_utils.cpp db_utils.h
	g++-8 -c -g db_utils.cpp

clean:
	-rm ./Domino
	-rm *.o
