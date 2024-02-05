NAME = checker
CC = gcc
SRCS = ./srcs/main.c ./srcs/parser.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
PS_A = ../push_swap/push_swap.a
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCDIRS) -g3 
all : $(NAME)

$(NAME) : $(OBJS) $(PS_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	cp $(NAME) ../push_swap

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $^

$(PS_A) :
	cd ../push_swap && make

clean :
	rm -rf $(OBJS)
	cd ../push_swap && rm -f $(NAME)

fclean : clean
	rm -rf $(NAME) libft.a

re : fclean all

.PHONY : all bonus clean fclean re
