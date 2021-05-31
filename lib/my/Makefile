##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile lib my_hunter
##

SRC	=	$(shell find -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f *~

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all
