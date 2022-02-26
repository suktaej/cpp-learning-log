CC = g++
CFLAGS = -W -Wall

TARGET_001 = namespace_exe
TARGET_002 = overloading_exe
TARGET_006 = calculator_exe
TARGET_007 = string_exe

OBJECTS_001 = 001_namespace.o 001_namespace_main.o
OBJECTS_002 = 002_swap_func_overloading.o
OBJECTS_006 = 006_cal_class.o 006_cal_class_main.o
OBJECTS_007 = 007_string.o 007_string_main.o
#all:$(TARGET)

#$(TARGET): $(OBJECTS)
#	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_001): $(OBJECTS_001)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_002): $(OBJECTS_002)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_006): $(OBJECTS_006)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_007): $(OBJECTS_007)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm *.o *_exe
