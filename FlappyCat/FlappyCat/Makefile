SRCDIR = .
INCLUDE = -I/opt/homebrew/include/

# Compilation Flags
CFLAGS=-std=c++11 $(INCLUDE)
# Linking Flags
LFLAGS=-L/opt/homebrew/lib -lsfml-graphics -lsfml-system -lsfml-window

CC=g++

.PHONY : all
all : game

# List of all object files to link together.
OBJS = main.o Cat.o Wall.o Grass.o WallQueue.o HelperFunction.o TestFunctions.o

main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $<

Cat.o: $(SRCDIR)/Cat.cpp
	$(CC) $(CFLAGS) -c $<

Wall.o: $(SRCDIR)/Wall.cpp
	$(CC) $(CFLAGS) -c $<

Grass.o: $(SRCDIR)/Grass.cpp
	$(CC) $(CFLAGS) -c $<

WallQueue.o: $(SRCDIR)/WallQueue.cpp 
	$(CC) $(CFLAGS) -c $<

HelperFunction.o: $(SRCDIR)/HelperFunction.cpp
	$(CC) $(CFLAGS) -c $<

TestFunctions.o: $(SRCDIR)/TestFunctions.cpp
	$(CC) $(CFLAGS) -c $<

game: $(OBJS)
	$(CC) $(LFLAGS) -o game $(OBJS)

