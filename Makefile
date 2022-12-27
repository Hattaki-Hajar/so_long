SOURCES = $(wildcard *.c)
		
CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	so_long

LIBFT	=	./libft/libft.a

LFLAGS	=	-lmlx -framework OpenGL -framework AppKit

all	:	$(NAME)

$(NAME)	:	$(SOURCES)
		make -C libft
		$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) $(LIBFT)  -o $(NAME)

clean:
		make clean -C libft

fclean	:	clean
			rm -rf $(NAME) $(LIBFT)

re	:	fclean all