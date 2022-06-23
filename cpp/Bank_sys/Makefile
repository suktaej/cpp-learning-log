CC = g++
CFLAGS = -g -W -Wall

TARGET = Bank_Sys_exe
OBJECTS = BankingSystemMain.o Account.o AccountHandler.o
#all:$(TARGET)

#$(TARGET): $(OBJECTS)
#	$(CC) $(CFLAGS) -o $@ $^

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean :
	rm *.o *_exe
