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
    sfSprite *mapSprite;
    sfEvent event;
    sfSprite *characterSprite;

    mapSprite = sfSprite_create();
    characterSprite = sfSprite_create();

    sfSprite_setTexture(mapSprite, mapTexture, sfTrue);
    sfSprite_setTexture(characterSprite, characterTexture, sfTrue);

    sfRenderWindow_setFramerateLimit(window, 60);

    // Set initial position for the character sprite
    sfVector2f characterPosition = {200.0f, 200.0f};
    sfSprite_setPosition(characterSprite, characterPosition);

    while (sfRenderWindow_isOpen(window)) {
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed) {
                    sfRenderWindow_close(window);
                }
            }

            // Example: Move the character using arrow keys
            if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
                characterPosition.x -= 2.0f; // Adjust the character's position
                sfSprite_setPosition(characterSprite, characterPosition); // Update the character's position
            } else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
                characterPosition.x += 2.0f;
                sfSprite_setPosition(characterSprite, characterPosition);
            }

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