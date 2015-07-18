CC=g++
CFLAGS=-c -Wall -I.
LDFLAGS=
SOURCES=Card.cpp Chips.cpp Players.cpp CardDeck.cpp Blackjack.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=cards

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ 
