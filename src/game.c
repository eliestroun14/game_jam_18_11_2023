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
#include <stdbool.h>

void handle_kill_ghost(int *numGhosts, ghost_t ghosts[], sfVector2i *mouseClickPos)
{
    printf("Mouse click position: x=%d, y=%d\n", mouseClickPos->x, mouseClickPos->y);

    for (int i = 0; i < *numGhosts; ++i) {
        sfFloatRect ghostBounds = sfSprite_getGlobalBounds(ghosts[i].sprite);

        // Check if the mouse click was inside the bounding box of the ghost sprite
        if (sfFloatRect_contains(&ghostBounds, mouseClickPos->x, mouseClickPos->y)) {
            // Remove the ghost by shifting elements in the array
            for (int j = i; j < *numGhosts - 1; ++j) {
                ghosts[j] = ghosts[j + 1];
            }
            (*numGhosts)--; // Reduce the number of ghosts in the array
            break; // Exit the loop after removing the clicked ghost
        }
    }
}

void handle_mouse_click(sfMouseButtonEvent event, int *ghostclicked, sfVector2i *mouseClickPos)
{
    printf("Mouse x=%d y=%d\n", event.x, event.y);
        mouseClickPos->x = event.x;
        mouseClickPos->y = event.y;
        *ghostclicked = 1;
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

    sfTexture *ghostTexture = sfTexture_createFromFile("assets/ghost1.png", NULL);
    if (!ghostTexture)
        exit(84);

    int numGhosts = 5;
    ghost_t ghosts[numGhosts];

    for (int i = 0; i < numGhosts; ++i) {
        initialize_ghost(&ghosts[i], ghostTexture);
    }

    sfVector2i mouseClickPos = {0, 0};
    int ghostclicked = 0;

    sfRenderWindow_setFramerateLimit(window, 60);

    mapSprite = sfSprite_create();
    characterSprite = sfSprite_create();

    sfSprite_setTexture(mapSprite, mapTexture, sfTrue);
    sfSprite_setTexture(characterSprite, characterTexture, sfTrue);

    sfVector2f characterPosition = {605.0f, 800.0f};
    sfSprite_setPosition(characterSprite, characterPosition);

    sfVector2f scaleFactor = {0.7f, 0.7f};
    sfSprite_setScale(characterSprite, scaleFactor);
    set_origin_character(characterTexture, characterSprite);

    while (sfRenderWindow_isOpen(window)) {
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(window);
                if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape))
                    resume_menu(window, gamestatus);
                if (event.type == sfEvtMouseButtonPressed)
                    handle_mouse_click(event.mouseButton, &ghostclicked, &mouseClickPos);
            }
            if (ghostclicked == 1)
                handle_kill_ghost(&numGhosts, ghosts, &mouseClickPos);
            for (int i = 0; i < numGhosts; ++i)
                update_ghost(&ghosts[i], characterPosition);

            handle_mouse(window, &mousePos, &mousePosWorld, characterSprite, &angle);

            sfSprite_setRotation(characterSprite, angle + 270);

            check_movement(&characterPosition, characterSprite, collisionMap);
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, mapSprite, NULL);
            sfRenderWindow_drawSprite(window, characterSprite, NULL);
            for (int i = 0; i < numGhosts; ++i)
                sfRenderWindow_drawSprite(window, ghosts[i].sprite, NULL);
            sfRenderWindow_display(window);
        }
    sfSprite_destroy(mapSprite);
    sfSprite_destroy(characterSprite);
    sfTexture_destroy(mapTexture);
    sfTexture_destroy(characterTexture);
    sfRenderWindow_destroy(window);
    for (int i = 0; i < numGhosts; ++i) {
        sfSprite_destroy(ghosts[i].sprite);
    }
    sfTexture_destroy(ghostTexture);
}

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
