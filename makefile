Domino: manage.o utils.o
	g++ -I/usr/local/include -L/usr/local/lib -o Domino *.o -lyaml-cpp
	@echo "Cleaning Up..."
	rm *.o

manage.o: manage.cpp
	g++ -c manage.cpp

utils.o: utils.cpp utils.h
	g++ -c utils.cpp

clean:
	-rm *.o
	-rm ./Domino
