CFLAGS = -std=c99 -pedantic -Wall -O4 -lm
INCS = parser.h test.h
TARGET = parser
SOURCES = test.c $(TARGET).c
LIBS = 
CC = gcc


all: $(TARGET)

$(TARGET): $(SOURCES) $(INCS)
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(LIBS)
	
clean:
	rm -f $(TARGET)
	
run: all
	$(TARGET) 
