/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** game
*/

#include <SFML/Graphics.h>

int main() {
    sfVideoMode mode = {1200, 1000, 64};
    sfRenderWindow *window;
    sfTexture *mapTexture;
    sfSprite *mapSprite;
    sfEvent event;

    window = sfRenderWindow_create(mode, "Game Window", sfResize | sfClose, NULL);
    if (!window) return -1;

    mapTexture = sfTexture_createFromFile("assets/map_v1.png", NULL);
    if (!mapTexture) return -1;

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