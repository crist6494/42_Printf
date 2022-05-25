
NAME	=	libftprintf.a

SRCS	=	ft_printf.c

OBJS	= $(SRCS:%.c=%.o)

CFLAGS	= -Wall -Wextra -Werror

$(NAME):
	make -C ./libft
	cp Libft/libft.a $(NAME)
	gcc $(CFLAGS) -c $(SRCS) -I./
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make clean -C ./libft
	rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re
