##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile root my_hunter
##

SRC	=	$(shell find -name "*.c")

NAME	=	my_hunter

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME) clean

libmy:
	@make -sC lib/my/

$(NAME):	libmy
	@gcc -o $(NAME) $(SRC) $(CSFML) -L./lib -lmy -g
	@echo -e "\033[05m\033[32mCompilation done => ${NAME}\033[00m"

clean:
	@make -sC lib/my/ clean
	@rm -f *~

fclean:	clean
	clear
	@make -sC lib/my/ fclean
	@rm -f $(NAME)

re: fclean all
