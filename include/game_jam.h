/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** game_jam
*/

#ifndef GAME_JAM_H_
    #define GAME_JAM_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

    #define M_PI 3.14159265358979323846
// anex
float calculateAngle(sfVector2f point1, sfVector2f point2);
// handle textures
sfRenderWindow *window_init(sfVideoMode mode);
sfTexture *map_texture_init(void);
sfTexture *character_texture_init(void);

// handle player movment
void check_movment(sfVector2f *characterPosition, sfSprite *characterSprite);

// handle player facing mouse
void handle_mouse(sfRenderWindow *window, sfVector2i *mousePos, sfVector2f *mousePosWorld,
    sfSprite *characterSprite, float *angle);
void set_origin_character(sfTexture *characterTexture, sfSprite *characterSprite);

#endif /* !GAME_JAM_H_ */
