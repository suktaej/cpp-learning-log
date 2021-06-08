CC = g++
CFLAGS = -W -Wall
TARGET = hello_exe
OBJECTS = memo.o cal.o hello.o

ALL : $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o hello_exe
