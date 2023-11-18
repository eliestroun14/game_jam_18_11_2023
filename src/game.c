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
    sfRenderWindow *window = window_init(mode);
    sfTexture *mapTexture = map_texture_init();
    sfTexture *characterTexture = character_texture_init();
    sfSprite *characterSprite;
    sfSprite *mapSprite;
    sfEvent event;

    mapSprite = sfSprite_create();
    characterSprite = sfSprite_create();

    sfSprite_setTexture(mapSprite, mapTexture, sfTrue);
    sfSprite_setTexture(characterSprite, characterTexture, sfTrue);

    sfRenderWindow_setFramerateLimit(window, 60);

    sfVector2f characterPosition = {200.0f, 200.0f};
    sfSprite_setPosition(characterSprite, characterPosition);

    sfVector2f scaleFactor = {0.75f, 0.75f};
    sfSprite_setScale(characterSprite, scaleFactor);

    while (sfRenderWindow_isOpen(window)) {
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed) {
                    sfRenderWindow_close(window);
                }
            }
            sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
            sfVector2f mousePosWorld = sfRenderWindow_mapPixelToCoords(window, mousePos, NULL);

            float angle = calculateAngle(sfSprite_getPosition(characterSprite), mousePosWorld);
            sfSprite_setRotation(characterSprite, angle + 90);

            check_movment(&characterPosition, characterSprite);

            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, mapSprite, NULL);
            sfRenderWindow_drawSprite(window, characterSprite, NULL); // Draw the character sprite
            sfRenderWindow_display(window);
        }
    sfSprite_destroy(mapSprite);
    sfSprite_destroy(characterSprite);
    sfTexture_destroy(mapTexture);
    sfTexture_destroy(characterTexture);
    sfRenderWindow_destroy(window);
    return 0;
}