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
    sfRenderWindow_setFramerateLimit(window, 60);
    sfTexture *mapTexture;
    sfSprite *mapSprite;

    window = sfRenderWindow_create(mode, "Game Window", sfResize | sfClose, NULL);
    if (!window) return -1;
    mapTexture = sfTexture_createFromFile("/../assets/map_v1.png", NULL);
    mapSprite = sfSprite_create();
    sfSprite_setTexture(mapSprite, mapTexture, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
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