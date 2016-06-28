CC=g++
CXXFLAGS=-std=c++0x
LDFLAGS=-lpng
SOURCES=fuzzpng.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pngtest

all: $(sources) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o $(OBJECTS) img
