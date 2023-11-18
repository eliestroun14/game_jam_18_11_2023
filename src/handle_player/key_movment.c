/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** key_movment
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void check_movment(sfVector2f *characterPosition, sfSprite *characterSprite)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        characterPosition->x -= 2.0f; // Adjust the character's position
        sfSprite_setPosition(characterSprite, *characterPosition); // Update the character's position
    } else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        characterPosition->x += 2.0f;
        sfSprite_setPosition(characterSprite, *characterPosition);
    } else if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        characterPosition->y -= 2.0f;
        sfSprite_setPosition(characterSprite, *characterPosition);
    } else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        characterPosition->y += 2.0f;
        sfSprite_setPosition(characterSprite, *characterPosition);
    }
}