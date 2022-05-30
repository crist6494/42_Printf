
NAME	=	libftprintf.a

SRCS	=	ft_printf.c 	\
			ft_checkerbase.c \
			ft_printf_utils.c \

OBJS	= $(SRCS:%.c=%.o)

CFLAGS	= -Wall -Wextra -Werror

$(NAME):
	gcc $(CFLAGS) -c $(SRCS) -I./
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re
