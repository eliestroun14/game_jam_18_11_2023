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

int initialize(sfRenderWindow *window, sfTexture *mapTexture,
    sfTexture *characterTexture, sfVideoMode mode)
{
    window = sfRenderWindow_create(mode, "Game Window", sfResize | sfClose, NULL);
    if (!window)
        return -84;

    mapTexture = sfTexture_createFromFile("assets/map_v1.png", NULL);
    if (!mapTexture)
        return -84;

    characterTexture = sfTexture_createFromFile("assets/skinsoldat4.png", NULL);
    if(!characterTexture)
        return -84;

    return 0;
}