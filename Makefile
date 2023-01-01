SOURCES = $(wildcard ./mandatory/*.c)

SRCBONUS 	= $(wildcard ./bonus/*.c)
		
CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	so_long

BNAME	=	so_long_bonus

LIBFT	=	./libft/libft.a

LFLAGS	=	-lmlx -framework OpenGL -framework AppKit


all:	$(NAME)

$(NAME):	$(SOURCES)
		make -C libft
		$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) $(LIBFT)  -o $(NAME)


bonus:	$(BNAME)

$(BNAME): $(SRCBONUS)
		make -C libft
		$(CC) $(CFLAGS) $(LFLAGS) $(SRCBONUS) $(LIBFT)  -o $(BNAME)


clean:
		make clean -C libft

fclean:	clean
			rm -rf $(NAME) $(LIBFT)

re:	fclean all