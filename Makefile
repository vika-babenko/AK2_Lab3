executable = simple_program

build: main.o
	g++ -o $(executable) main.o

main.o:
	g++ -c main.cpp

clean:
	rm -f main.o $(executable)