main: main.o
	g++ main.o -o ki -L../SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -I../SFML-2.5.1/include

clear:
	rm main.o sfml-app