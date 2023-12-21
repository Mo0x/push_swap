NAME = push_swap
CC = gcc 
SRCS = ./srcs/main.c ./srcs/arg_check.c ./srcs/d_list_utils.c ./srcs/arg_parser.c ./srcs/ft_split_wc.c ./srcs/error_free.c ./srcs/push_swap.c ./srcs/quick_sort/ft_quick_sort.c ./srcs/tinysort/ft_tiny_sort.c ./srcs/instructions/pushes.c ./srcs/instructions/swaps.c ./srcs/instructions/rotates.c ./srcs/instructions/reverses.c ./srcs/layering.c ./srcs/push_b.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCDIRS) -g3 -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft/
	mv ./libft/libft.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lft

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	make clean -C ./libft/
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) libft.a

re : fclean all

.PHONY : all bonus clean fclean re
