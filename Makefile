NAME = libftprintf.a
SRCS =\
	ft_printf.c\
	process_csper.c\
	process_diux.c\
	process_p.c\
	ft_putnum.c\
	ft_putstr.c\
	etc.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
	
.PHONY: all clean fclean re .c.o
