CC = gcc
CFLAGS = -Wall -std=c99
TARGET = main
OBJECTS = $(TARGET).o clist.o

$(TARGET) : $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o : %.c
		$(CC) $(CFLAGS) -c $<
