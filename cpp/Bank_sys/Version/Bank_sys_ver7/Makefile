CC = gcc
CFLAGS = -g -W -Wall

CPP = g++
CPPFLAGS = -g -W -Wall

TARGET = Bank_Sys_exe
OBJECTS = BankingSystemMain.o Account.o AccountHandler.o
#all:$(TARGET)

#$(TARGET): $(OBJECTS)
#	$(CC) $(CFLAGS) -o $@ $^

$(TARGET): $(OBJECTS)
	$(CPP) $(CPPFLAGS) -o $@ $^
clean :
	rm *.o *_exe
