/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** window_texture_map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

sfRenderWindow *window_init(sfVideoMode mode)
{
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "Game Window", sfResize | sfClose, NULL);
    if (!window)
        exit(84);
    return window;
}

sfTexture *map_texture_init(void)
{
    sfTexture *mapTexture;

    mapTexture = sfTexture_createFromFile("assets/collisions_map.png", NULL);
    if (!mapTexture)
        exit (84);
    return mapTexture;
}

sfTexture *character_texture_init(void)
{
    sfTexture *characterTexture;

    characterTexture = sfTexture_createFromFile("assets/skinsoldat4.png", NULL);
    if(!characterTexture)
        exit(84);
    return characterTexture;
}