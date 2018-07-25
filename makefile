TARGET = main
LIBS = -lm
CC = g++
CFLAGS = -g -Wall
RM = rm -f

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(LIBS)

clean:
	$(RM) $(TARGET) *.o
