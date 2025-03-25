program: labb1.cpp address.cpp person.cpp address.h person.h
	g++ -o program labb1.cpp address.cpp person.cpp

run: program
	./program

clean:
	rm labb1

