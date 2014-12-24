CFLAGS = -std=c99 -pedantic -Wall -O4 -lm
INCS = parser.h test.h ashley_sdl.h
TARGET = parser
SOURCES = test.c ashley_sdl.c $(TARGET).c
LIBS = -lSDL2
CC = gcc

all: $(TARGET)

$(TARGET): $(SOURCES) $(INCS)
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(LIBS)
	
clean:
	rm -f $(TARGET)
	
run: all
	$(TARGET) 
