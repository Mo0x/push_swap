NAME = checker
CC = gcc
SRCS = ./srcs/main.c ./srcs/parser.c ./srcs/ps_utils/arg_check.c ./srcs/ps_utils/arg_parser.c ./srcs/gnl/get_next_line_utils.c ./srcs/gnl/get_next_line.c ./srcs/instructions/pushes.c ./srcs/instructions/reverses.c ./srcs/instructions/rotates.c ./srcs/instructions/swaps.c ./srcs/minilib/ft_atoi.c ./srcs/minilib/ft_atoll.c ./srcs/minilib/ft_isdigit.c ./srcs/minilib/ft_split_wc.c ./srcs/minilib/ft_bzero.c ./srcs/minilib/ft_split.c ./srcs/minilib/ft_calloc.c ./srcs/ps_utils/linked_list0.c ./srcs/ps_utils/linked_list1.c ./srcs/ps_utils/linked_list2.c ./srcs/ps_utils/error_free.c ./srcs/minilib/ft_printf/ft_hexa.c ./srcs/minilib/ft_printf/ft_numbers.c ./srcs/minilib/ft_printf/ft_pointer.c ./srcs/minilib/ft_printf/ft_printf.c ./srcs/minilib/ft_printf/ft_printpc.c ./srcs/minilib/ft_printf/ft_string.c ./srcs/minilib/ft_putchar_fd.c ./srcs/minilib/ft_putnbr_fd.c ./srcs/minilib/ft_putstr_fd.c 
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCDIRS) -g3 

all : $(NAME)

$(NAME) : $(OBJS) $(PS_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	cp $(NAME) ../push_swap

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
