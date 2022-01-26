NAME = ft_do-op
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)
	$(CC) $(CFLAGS) *.o -o $(NAME) -I.
	
$(NAME) :
	$(CC) $(CFLAGS) -c *.c
	
clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all