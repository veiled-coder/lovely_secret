TARGET = my_mastermind
OBJ = my_mastermind.o
FILE = my_mastermind.c
CFLAGS = -Wall -Werror -Wextra

all : $(TARGET)

$(TARGET): $(OBJ)
	gcc $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ): $(FILE)	
	gcc $(CFLAGS) -c $(FILE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all