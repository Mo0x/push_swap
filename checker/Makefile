NAME = checker
CC = gcc
SRCS = ./srcs/main.c ./srcs/parser.c
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
