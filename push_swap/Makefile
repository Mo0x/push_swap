NAME = push_swap
CC = gcc 
SRCS = ./srcs/main.c ./srcs/arg_check.c ./srcs/list_stack_utils/d_list_utils_0.c ./srcs/list_stack_utils/d_list_utils_1.c ./srcs/list_stack_utils/d_list_utils_2.c ./srcs/list_stack_utils/d_list_utils_3.c ./srcs/arg_parser.c ./srcs/ft_split_wc.c ./srcs/error_free.c ./srcs/push_swap.c ./srcs/quick_sort/ft_quick_sort.c ./srcs/tinysort/ft_tiny_sort.c ./srcs/instructions/pushes.c ./srcs/instructions/swaps.c ./srcs/instructions/rotates.c ./srcs/instructions/reverses.c ./srcs/layer/layering.c ./srcs/layer/layer_util.c ./srcs/push_b.c ./srcs/push_b2.c ./srcs/push_node.c ./srcs/print_lst.c ./srcs/optimize_path/merge.c ./srcs/optimize_path/purge.c ./srcs/optimize_path/delete_node.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCDIRS) -g3
ARCHIVE = push_swap.a

all : $(NAME)

$(NAME) : $(ARCHIVE)
	make -C ./libft/
	mv ./libft/libft.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lft

$(ARCHIVE) : $(OBJS)
	ar -rcs $(ARCHIVE) $^

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean :
	make clean -C ./libft/
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) libft.a

re : fclean all

.PHONY : all bonus clean fclean re
