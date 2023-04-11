
NAME = libftprintf.a
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
LIBFT_NAME = ./libft/libft.a
LIBFT_SRC = libft
SRCS = ft_printf.c ft_printf_util_count.c ft_printf_util_format_1.c ft_printf_util_format_2.c ft_printf_util_print_1.c ft_printf_util_print_2.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_NAME)
	mv $(LIBFT_NAME) $@
	$(AR) $@ $(OBJS)

$(LIBFT_NAME) :
	make -C $(LIBFT_SRC) all bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	make -C $(LIBFT_SRC) clean
	rm -rf $(OBJS)

fclean : clean
	make -C $(LIBFT_SRC) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re