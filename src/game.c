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

int main(void)
{
    sfVideoMode mode = {1200, 1000, 64};
    sfRenderWindow *window = window_init(mode);
    sfTexture *mapTexture = map_texture_init();
    sfTexture *characterTexture = character_texture_init();
    sfSprite *characterSprite;
    sfSprite *mapSprite;
    sfEvent event;
    sfVector2i mousePos;
    sfVector2f mousePosWorld;
    float angle;
    sfImage* collisionMap = sfImage_createFromFile("assets/collisions_map.png");
    if (!collisionMap)
        exit(84);

    sfRenderWindow_setFramerateLimit(window, 60);

    mapSprite = sfSprite_create();
    characterSprite = sfSprite_create();

    sfSprite_setTexture(mapSprite, mapTexture, sfTrue);
    sfSprite_setTexture(characterSprite, characterTexture, sfTrue);

    sfVector2f characterPosition = {500.0f, 200.0f};
    sfSprite_setPosition(characterSprite, characterPosition);

    sfVector2f scaleFactor = {0.75f, 0.75f};
    sfSprite_setScale(characterSprite, scaleFactor);
    set_origin_character(characterTexture, characterSprite);

    while (sfRenderWindow_isOpen(window)) {
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed) {
                    sfRenderWindow_close(window);
                }
            }

            handle_mouse(window, &mousePos, &mousePosWorld, characterSprite, &angle);

            sfSprite_setRotation(characterSprite, angle + 270);

            check_movement(&characterPosition, characterSprite, collisionMap);

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