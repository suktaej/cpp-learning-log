CC = g++
CFLAGS = -g -W -Wall

TARGET_001 = namespace_exe
TARGET_002 = overloading_exe
TARGET_006 = calculator_exe
TARGET_007 = string_exe
TARGET_009 = rectangle_exe
TARGET_055 = point_template_exe
TARGET_056 = point_exe

OBJECTS_001 = 001_namespace.o 001_namespace_main.o
OBJECTS_002 = 002_swap_func_overloading.o
OBJECTS_006 = 006_cal_class.o 006_cal_class_main.o
OBJECTS_007 = 007_string.o 007_string_main.o
OBJECTS_009 = 009_point.o 009_rectangle.o 009_main.o
OBJECTS_055 = 055_PointTemplate.o 055_PointTemplateMain.o
OBJECTS_056 = 056_Point.o 056_BoundArrayMain.o
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

$(TARGET_009): $(OBJECTS_009)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_055): $(OBJECTS_055)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_056): $(OBJECTS_056)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm *.o *_exe
