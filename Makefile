
NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_putstr.c ft_putnbr.c ft_putchar.c \
	ft_printf.c ft_put_unsigned.c ft_put_hex.c \
	ft_put_pointer.c ft_printf_format.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
