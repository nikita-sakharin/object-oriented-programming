CC=g++
CFLAGS=-c -std=c++14 -Werror -pedantic -Wall -Wextra -o3
SOURCES=main.cpp figure.cpp pentagon.cpp queue_item.cpp queue.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=LW_2

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -frd $(OBJECTS) $(EXECUTABLE)
