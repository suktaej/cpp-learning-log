CC = g++
CFLAGS = -W -Wall

TARGET_001 = namespace_exe
TARGET_002 = overloading_exe

OBJECTS_001 = 001_namespace.o 001_namespace_main.o
OBJECTS_002 = 002_swap_func_overloading.o

#all:$(TARGET)

#$(TARGET): $(OBJECTS)
#	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_001): $(OBJECTS_001)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_002): $(OBJECTS_002)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm *.o $(TARGET_001) $(TARGET_002)
