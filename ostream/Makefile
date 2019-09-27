CC=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=
SOURCES=main.cpp test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=executable.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f /p/t/h *.o executable.exe
