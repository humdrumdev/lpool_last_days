NAME = ft_display_file
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = display_file.c
OBJ = display_file.o main.o
MAIN = main.c

all : $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	

$(NAME) :
	$(CC) $(CFLAGS) -c $(SRC) $(MAIN)
	
clean :
	/bin/rm -rf $(OBJ)

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all
