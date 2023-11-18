/*
** EPITECH PROJECT, 2023
** dandgereuse est la nuit
** File description:
** resume_menu.c
*/

#include "../include/game_jam.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

static int check_event(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape)) {
            return 1;
            }
        return 0;
    }
}

void resume_menu(sfRenderWindow *window)
{
    sfEvent event;
    sfTexture *background = sfTexture_createFromFile("assets/resume_menu/background.png", NULL);
    sfSprite *bg_sprite = sfSprite_create();

    sfVector2f scale = {1.12, 1.12};
    sfVector2f scale_button = {1, 1};

    sfVector2f pos_button = {500, 500};
    sfVector2f pos_button02 = {500, 650};
    sfVector2f pos_button03 = {500, 800};

    sfSprite_setTexture(bg_sprite, background, sfTrue);
    sfSprite_setScale(bg_sprite, scale);

    while (sfRenderWindow_isOpen(window)) {
        if (check_event(window, &event) == 1)
            return;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);
        display_resume_button(window, scale_button, pos_button);
        display_restart_button(window, scale_button, pos_button02);
        display_menu_button(window, scale_button, pos_button03);
        // if_click_play(window, event);
        // if_click_quit(window, event);
        sfRenderWindow_display(window);
    }
}
