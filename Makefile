CXX=g++

FLAGS= -Wall -Wextra

SRC= main.cpp InputParser.cpp CommandHandler.cpp

LIBS=

INCL=

EXE= duppe

all:
	$(CXX) $(FLAGS) $(SRC) $(LIBS) $(INCL) -o $(EXE)
