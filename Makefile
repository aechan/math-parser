CC = g++
CFLAGS = -c -Wall -Iinclude
LDFLAGS =
SRC = src/
SOURCES = $(SRC)math-lexer.cpp $(SRC)main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = math
OUTDIR = out/

all: setup build

setup:
	mkdir -p $(OUTDIR)

build: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(subst src/,out/,$(OBJECTS)) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $(subst src/,out/,$@)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)