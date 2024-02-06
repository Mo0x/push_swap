NAME = checker
CC = gcc
SRCS = ./srcs/main.c ./srcs/parser.c ./srcs/ps_utils/arg_check.c ./srcs/ps_utils/arg_parser.c ./srcs/gnl/get_next_line_utils.c ./srcs/gnl/get_next_line.c ./srcs/instructions/pushes.c ./srcs/instructions/reverses.c ./srcs/instructions/rotates.c ./srcs/instructions/swaps.c
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
