/*
** EPITECH PROJECT, 2023
** main_menu.c
** File description:
** game
*/

#include "../include/game_jam.h"
#include <SFML/Graphics.h>
#include <stdio.h>

void if_click_play(sfRenderWindow *window, sfEvent event, int *gameStarted) {
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 508 && mouse.x <= 761 && mouse.y >= 485 && mouse.y <= 554) {
        if (event.type == sfEvtMouseButtonPressed) {
            *gameStarted = 1;
        }
    }
}

void if_click_quit(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if(mouse.x >= 508 && mouse.x <= 761) {
        if (mouse.y >= 627 && mouse.y <= 690) {
            if (event.type == sfEvtMouseButtonPressed) {
                sfRenderWindow_close(window);
            }
        }
    }
}

void menu(sfRenderWindow *window)
{
    sfTexture *main_menu = sfTexture_createFromFile("assets/main_menu.png", NULL);
    sfSprite *menu_sprite = sfSprite_create();

    sfTexture *start_button = sfTexture_createFromFile("assets/main_menu/play.png", NULL);
    sfSprite *start_sprite = sfSprite_create();

    sfTexture *exit_button = sfTexture_createFromFile("assets/main_menu/exit.png", NULL);
    sfSprite *exit_sprite = sfSprite_create();

    sfVector2f scale = {1.12, 1.12};
    sfVector2f scale_button = {1, 1};
    sfVector2f scale_button02 = {1, 1};

    sfVector2f pos_button = {500, 500};
    sfVector2f pos_button02 = {500, 650};

    sfSprite_setTexture(menu_sprite, main_menu, sfTrue);
    sfSprite_setScale(menu_sprite, scale);

    sfSprite_setTexture(start_sprite, start_button, sfTrue);
    sfSprite_setScale(start_sprite, scale_button);
    sfSprite_setPosition(start_sprite, pos_button);

    sfSprite_setTexture(exit_sprite, exit_button, sfTrue);
    sfSprite_setScale(exit_sprite, scale_button02);
    sfSprite_setPosition(exit_sprite, pos_button02);

    int gameStarted = 0;
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, menu_sprite, NULL);
        sfRenderWindow_drawSprite(window, start_sprite, NULL);
        sfRenderWindow_drawSprite(window, exit_sprite, NULL);
        if_click_play(window, event, &gameStarted);
        if_click_quit(window, event);
        sfRenderWindow_display(window);
    }

    sfSprite_destroy(menu_sprite);
    sfSprite_destroy(start_sprite);
    sfSprite_destroy(exit_sprite);
    sfTexture_destroy(main_menu);
    sfTexture_destroy(start_button);
    sfTexture_destroy(exit_button);
}