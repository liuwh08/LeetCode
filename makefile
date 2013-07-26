CC=clang++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=TwoSum.cpp TwoSum_Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=TwoSum

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

