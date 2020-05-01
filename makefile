Domino: manage.o utils.o pugixml.o
	g++ -o Domino *.o
	@echo "Cleaning Up..."
	rm *.o

manage.o: manage.cpp
	g++ -c manage.cpp

utils.o: utils.cpp utils.h
	g++ -c utils.cpp

pugixml.o: pugixml/pugixml.cpp pugixml/pugixml.hpp pugixml/pugiconfig.hpp
	g++ -c pugixml/pugixml.cpp

clean:
	-rm *.o
	-rm ./Domino
