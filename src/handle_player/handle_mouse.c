/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** handle_mouse
*/

#include "../../include/game_jam.h"

void handle_mouse(sfRenderWindow *window, sfVector2i *mousePos, sfVector2f *mousePosWorld,
    sfSprite *characterSprite, float *angle)
{
    *mousePos = sfMouse_getPositionRenderWindow(window);
    *mousePosWorld = sfRenderWindow_mapPixelToCoords(window, *mousePos, NULL);

    *angle = calculateAngle(sfSprite_getPosition(characterSprite), *mousePosWorld);
}

void set_origin_character(sfTexture *characterTexture, sfSprite *characterSprite)
{
    sfVector2u characterTextureSize = sfTexture_getSize(characterTexture);
    sfVector2f characterTextureCenter = {characterTextureSize.x / 2.0f, characterTextureSize.y / 2.0f};

    // Set the origin to the center of the sprite
    sfSprite_setOrigin(characterSprite, characterTextureCenter);
}