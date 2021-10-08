##
## EPITECH PROJECT, 2019
## Infin_add
## File description:
## Infin_add of CPool_infinadd_2019
##

SRC	=	main.c\
		init_struct.c\
		draw.c\
		tools.c\
		player.c\
		player2.c\
		ai.c\
		gnl.c\

NAME	=	matchstick

all: $(NAME)

$(NAME):
	@$(MAKE) -C ./lib/my
	@gcc -g $(SRC) -o $(NAME) -L./lib -lmy

clean:
	@$(MAKE) -C ./lib/my clean

fclean:		clean
	@rm -f $(NAME)
	@$(MAKE) -C ./lib/my fclean

re:	fclean all
