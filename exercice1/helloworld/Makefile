# Juste changer les sources pour un nouveau projet 

SRC = hello.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

PROG = main

DEBUG = -g
COMPILE = g++ -c $(DEBUG) -I /usr/local/include
LINK = g++ $(DEBUG) -L /usr/local/lib -lgtest
MKDEP = g++ -MM

all : $(PROG)

clean: 
	rm -rf $(OBJ) $(PROG) deps.make

$(PROG) : $(OBJ)
	$(LINK) -o $(PROG) $(OBJ)

%.o : %.cpp
	$(COMPILE) $<

deps.make : $(SRC)
	$(MKDEP) $(SRC) > $@

include deps.make


# all: main

# main: main.o hello.o
# 	g++ -o main main.o hello.o

# main.o: main.cpp hello.hpp
# 	g++ -c main.cpp

# hello.o: hello.cpp hello.hpp
# 	g++ -c hello.cpp

# clean:
# 	rm -rf *.o
