TARGET = Quest_1
CC = gcc

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o ../build/$(TARGET)
	rm *.o

%.o : %.c
	$(CC) -c $< -o $@

rebuild: clean all

clean :
	rm $(TARGET) *.o