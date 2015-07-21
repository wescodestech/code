CC=g++
CFLAGS=-c -Wall -I.
LDFLAGS=-lX11 -lImlib2
SOURCES=img.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=img

all: $(sources) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o $(OBJECTS) img
