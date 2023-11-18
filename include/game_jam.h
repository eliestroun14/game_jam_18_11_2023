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

sfRenderWindow *window_init(sfVideoMode mode);
sfTexture *map_texture_init(void);
sfTexture *character_texture_init(void);

#endif /* !GAME_JAM_H_ */
