CC=g++
CFLAGS=-c -std=c++14 -Werror -pedantic -Wall -Wextra -o3
SOURCES=main.cpp figure.cpp pentagon.cpp hexagon.cpp octagon.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=LW_1

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -frd $(OBJECTS) $(EXECUTABLE)
