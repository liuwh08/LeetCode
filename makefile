CC=clang++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=findMedianSortedArrays.cpp findMedianSortedArrays_Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=findMedianSortedArrays

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

