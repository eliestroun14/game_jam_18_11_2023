/*
** EPITECH PROJECT, 2023
** main_menu.c
** File description:
** game
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "game.c"

void if_click_play(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if(mouse.x >= 508 && mouse.x <= 761) {
        if (mouse.y >= 485 && mouse.y <= 554) {
            if (event.type == sfEvtMouseButtonPressed) {
                sfRenderWindow_close(window);
                game();
            }
        }
    }
}

void if_click_quit(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if(mouse.x >= 508 && mouse.x <= 761) {
        if (mouse.y >= 627 && mouse.y <= 690) {
            if (event.type == sfEvtMouseButtonPressed) {
                sfRenderWindow_close(window);
            }
            
        }
    }
}

int main()
{
    sfVideoMode mode = {1200, 1080, 64};
    sfRenderWindow *window;
    sfEvent event;

    sfTexture *Texture = sfTexture_createFromFile("assets/main_menu.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfTexture *Texture02 = sfTexture_createFromFile("assets/start-button.png", NULL);
    sfSprite *button = sfSprite_create();

    sfTexture *Texture03 = sfTexture_createFromFile("assets/start-button.png", NULL);
    sfSprite *button02 = sfSprite_create();    

    sfVector2f scale = {1.12, 1.12};
    sfVector2f scale_button = {10, 10};
    sfVector2f scale_button02 = {10, 10};

    sfVector2f pos_button = {500, 500};
    sfVector2f pos_button02 = {500, 650};

    sfSprite_setTexture(sprite, Texture, sfTrue);
    sfSprite_setScale(sprite, scale);

    sfSprite_setTexture(button, Texture02, sfTrue);
    sfSprite_setScale(button, scale_button);
    sfSprite_setPosition(button, pos_button);

    sfSprite_setTexture(button02, Texture03, sfTrue);
    sfSprite_setScale(button02, scale_button02);
    sfSprite_setPosition(button02, pos_button02);

    window = sfRenderWindow_create(mode, "Game Window", sfResize | sfClose, NULL);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, button, NULL);
        sfRenderWindow_drawSprite(window, button02, NULL);
        if_click_play(window, event);
        if_click_quit(window, event);
        sfRenderWindow_display(window);
    }
    return 0;
}
