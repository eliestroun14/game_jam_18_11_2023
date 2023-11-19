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

void handle_mouse_click(sfMouseButtonEvent event)
{
    printf("Mouse x=%d y=%d\n", event.x, event.y);
}

void game(int *gamestatus)
{
    sfVideoMode mode = {1000, 838, 64};
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

    sfVector2f scaleFactor = {0.7f, 0.7f};
    sfSprite_setScale(characterSprite, scaleFactor);
    set_origin_character(characterTexture, characterSprite);

    while (sfRenderWindow_isOpen(window)) {
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed) {
                    sfRenderWindow_close(window);
                }
                if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape))
                    resume_menu(window, gamestatus);
                if (event.type == sfEvtMouseButtonPressed)
                    handle_mouse_click(event.mouseButton);
            }

            handle_mouse(window, &mousePos, &mousePosWorld, characterSprite, &angle);

            sfSprite_setRotation(characterSprite, angle + 270);

            check_movement(&characterPosition, characterSprite, collisionMap);

            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, mapSprite, NULL);
            sfRenderWindow_drawSprite(window, characterSprite, NULL);
            sfRenderWindow_display(window);
        }
    sfSprite_destroy(mapSprite);
    sfSprite_destroy(characterSprite);
    sfTexture_destroy(mapTexture);
    sfTexture_destroy(characterTexture);
    sfRenderWindow_destroy(window);
}

//int check_game_status(sfRenderWindow *window, int *game_status)
//{
//    if (!game_status)
//        menu(window, &game_status);
//    if (game_status == 1)
//        game(&game_status);
//}

int main(void)
{
    int game_status = 0;
    sfVideoMode mode = {1184, 992, 64};
    sfRenderWindow *window = window_init(mode);

    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        if (!game_status)
            menu(window, &game_status);
        if (game_status == 1)
            game(&game_status);
    }
    sfRenderWindow_destroy(window);
    return 0;
}