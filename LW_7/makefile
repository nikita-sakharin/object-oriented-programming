CC=g++
CFLAGS=-c -std=c++14 -Werror -pedantic -Wall -Wextra -O3
LDFLAGS=
SOURCES=queue_item.cpp queue.cpp stack_item.cpp stack.cpp allocator.cpp figure.cpp pentagon.cpp hexagon.cpp octagon.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=LW_6

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -frd $(OBJECTS) $(EXECUTABLE)