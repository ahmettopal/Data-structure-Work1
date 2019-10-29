ALL: Compile Run
Compile:
	g++ -I ./include -o ./lib/Student.o -c ./src/Student.cpp
	g++ -I ./include -o ./lib/Class.o -c ./src/Class.cpp
	g++ -I ./include -o ./lib/School.o -c ./src/School.cpp
	g++ -I ./include -o ./lib/Admin.o -c ./src/Admin.cpp
	g++ -I ./include -o ./bin/Program ./lib/Student.o ./lib/Class.o ./lib/School.o ./lib/Admin.o ./src/main.cpp
Run:
	./bin/Program