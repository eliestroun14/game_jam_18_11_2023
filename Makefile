##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	= jam_game

SRC		= ./src/game.c
SRC		+= ./src/handle_textures/window_texture_map.c
SRC		+= ./src/handle_player/key_movment.c
SRC		+= ./src/anex/calculate_angle.c
SRC		+= ./src/handle_player/handle_collisions.c
SRC		+= ./src/handle_player/handle_mouse.c
SRC		+= ./src/main_menu.c
SRC		+= ./src/resume_menu/display_buttons.c
SRC		+= ./src/resume_menu/resume_menu.c

LDFLAGS	= -L. -I include/

all: $(NAME)
.PHONY:

$(NAME):
		gcc -o $(NAME) $(SRC) -L /usr/lib/ -I/usr/include -lcsfml-graphics -lcsfml-window -lcsfml-system -lm -g

clean:
	$(RM) $(OBJS)
.PHONY:clean

fclean: clean
	$(RM) -f $(NAME)
.PHONY:fclean

re: fclean all
.PHONY:re
