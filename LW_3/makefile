CC=g++
CFLAGS=-c -std=c++14 -Werror -pedantic -Wall -Wextra -O3
SOURCES=main.cpp figure.cpp pentagon.cpp hexagon.cpp octagon.cpp queue_item.cpp queue.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=LW_4

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -frd *.o $(EXECUTABLE)