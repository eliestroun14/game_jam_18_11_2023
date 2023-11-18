##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	= jam_game

SRC		= ./src/game.c

LDFLAGS	= -L.  -I include/

all: $(NAME)
.PHONY:

$(NAME):
		gcc $(SRC) -L /usr/lib/ -I/usr/include -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

clean:
	$(RM) $(OBJS)
.PHONY:clean

fclean: clean
	$(RM) -f $(NAME)
.PHONY:fclean

re: fclean all
.PHONY:re