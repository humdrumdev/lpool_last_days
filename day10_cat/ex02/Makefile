NAME = ft_tail
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ./src/*.c
OBJ = obj
INC = ./includes

all : $(NAME)
	$(CC) $(CFLAGS) $(OBJ)/*.o -o $(NAME) -I $(INC)
	
$(NAME) :
	$(CC) $(CFLAGS) -c $(SRC)
	mv *.o $(OBJ)/
	
clean :
	rm -rf $(OBJ)/*.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
