NAME = push_swap
CC = gcc 
SRCS = ./srcs/main.c 
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCDIRS)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft/
	mv ./libft/libft.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lft

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	make clean -C ./libft/
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME) libft.a

re : fclean all

.PHONY : all bonus clean fclean re
