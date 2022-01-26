NAME = ft_cat
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ./src/*.c
OBJ = obj
INC = ./includes

all : $(NAME)
	$(CC) $(CFLAGS) $(OBJ)/*.o -o $(NAME)
	

$(NAME) :
	$(CC) $(CFLAGS) -c $(SRC) -I$(INC)
	/bin/mv *.o $(OBJ)/
	
clean :
	/bin/rm -rf $(OBJ)/*.o

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all
