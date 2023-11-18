/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** game
*/

#include "../include/game_jam.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    sfVideoMode mode = {1200, 1000, 64};
    sfRenderWindow *window;
    sfTexture *mapTexture;
    sfSprite *mapSprite;
    sfEvent event;
    sfTexture *characterTexture;
    sfSprite *characterSprite;

    if (initialize(window, mapTexture, characterTexture, mode) == 84) {
        printf("an error occured while initializing");
        exit(84);
    }

    mapSprite = sfSprite_create();

    sfSprite_setTexture(mapSprite, mapTexture, sfTrue);

    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, mapSprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(mapSprite);
    sfTexture_destroy(mapTexture);
    sfRenderWindow_destroy(window);
    return 0;
}