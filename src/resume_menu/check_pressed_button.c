/*
** EPITECH PROJECT, 2023
** dangereuse est la nuit
** File description:
** check_pressed_button.c
*/

#include "../../include/game_jam.h"
#include <SFML/Graphics.h>

int is_resume(sfRenderWindow *window, sfEvent event, int *gamestarter) /* resume the game */
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 405 && mouse.x <= 590 && mouse.y >= 300 && mouse.y <= 370) {
        if (event.type == sfEvtMouseButtonPressed) {
            printf("resume.\n");
            return 1;
        }
        return 0;
    }
    return 0;
}

int is_restart(sfRenderWindow *window, sfEvent event, int *gamestarter) /* restart the game */
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 405 && mouse.x <= 590 && mouse.y >= 460 && mouse.y <= 530) {
        if (event.type == sfEvtMouseButtonPressed) {
            *gamestarter = 1;
            printf("Restarting the game.\n");
            return 1;
        }
        return 0;
    }
    return 0;
}

int is_menu(sfRenderWindow *window, sfEvent event, int *gamestarter) /* goes back to main menu */
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 405 && mouse.x <= 590 && mouse.y >= 600 && mouse.y <= 670) {
        if (event.type == sfEvtMouseButtonPressed) {
            *gamestarter = 0;
            printf("Retour au menu principal.\n");
        }
        return 0;
    }
    return 0;
}
