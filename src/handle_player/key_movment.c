/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** key_movment
*/

#include "../../include/game_jam.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void check_movement(sfVector2f *characterPosition, sfSprite *characterSprite, sfImage *collisionMap)
{
    float moveAmount = 2.0f; // Adjust movement speed as needed

    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        sfVector2f nextPosition = *characterPosition;
        nextPosition.x -= moveAmount;

        // Check collision at the next intended position
        if (!checkCollision(nextPosition, collisionMap)) {
            *characterPosition = nextPosition;
            sfSprite_setPosition(characterSprite, *characterPosition);
        }
    } else if (sfKeyboard_isKeyPressed(sfKeyD)) {
        sfVector2f nextPosition = *characterPosition;
        nextPosition.x += moveAmount;

        if (!checkCollision(nextPosition, collisionMap)) {
            *characterPosition = nextPosition;
            sfSprite_setPosition(characterSprite, *characterPosition);
        }
    } else if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        sfVector2f nextPosition = *characterPosition;
        nextPosition.y -= moveAmount;

        if (!checkCollision(nextPosition, collisionMap)) {
            *characterPosition = nextPosition;
            sfSprite_setPosition(characterSprite, *characterPosition);
        }
    } else if (sfKeyboard_isKeyPressed(sfKeyS)) {
        sfVector2f nextPosition = *characterPosition;
        nextPosition.y += moveAmount;

        if (!checkCollision(nextPosition, collisionMap)) {
            *characterPosition = nextPosition;
            sfSprite_setPosition(characterSprite, *characterPosition);
        }
    }
}