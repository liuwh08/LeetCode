CC=clang++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=$(EXECUTABLE).cpp $(EXECUTABLE)_Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=fullJustify

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

