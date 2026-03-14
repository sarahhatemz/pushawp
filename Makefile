CC = cc

CFLAGS = -Wall -Werror -Wextra 

SRCS = main.c stack.c sort.c parsing.c parsing2.c parsing3.c ops.c ops2.c reverse_rotate.c

OBJ = $(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT_A = libft/libft.a

NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ)  -o $@ -L $(LIBFT_DIR) -lft

$(LIBFT_A) :
	make -C $(LIBFT_DIR)
clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ)
fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re