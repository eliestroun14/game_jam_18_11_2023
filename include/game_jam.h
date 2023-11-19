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

typedef struct ghost {
    sfSprite* sprite;
    sfVector2f velocity;
} ghost_t;

// handle mobs
void initialize_ghost(ghost_t *ghost, sfTexture *ghostTexture);
void update_ghost(ghost_t *ghost, sfVector2f playerPosition);

int main(void);
int check_game_status(sfRenderWindow *window, int *game_status);
// anex
float calculateAngle(sfVector2f point1, sfVector2f point2);

// handle textures
sfRenderWindow *window_init(sfVideoMode mode);
sfTexture *map_texture_init(void);
sfTexture *character_texture_init(void);

// handle player movement
void check_movement(sfVector2f *characterPosition,
    sfSprite *characterSprite, sfImage *collisionMap);

// handle player facing mouse
void handle_mouse(sfRenderWindow *window, sfVector2i *mousePos, sfVector2f *mousePosWorld,
    sfSprite *characterSprite, float *angle);
void set_origin_character(sfTexture *characterTexture, sfSprite *characterSprite);

// handle collisions
int checkCollision(sfVector2f position, sfImage* collisionMap);

// menu
void menu(sfRenderWindow *window, int *gamestarted);
int resume_menu(sfRenderWindow *window, int *gamestatus);
void display_resume_button(sfRenderWindow *window, sfVector2f scale, sfVector2f pos);
void display_restart_button(sfRenderWindow *window, sfVector2f scale, sfVector2f pos);
void display_menu_button(sfRenderWindow *window, sfVector2f scale, sfVector2f pos);
int is_resume(sfRenderWindow *window, sfEvent event, int *gamestarter);
int is_restart(sfRenderWindow *window, sfEvent event, int *gamestarter);
int is_menu(sfRenderWindow *window, sfEvent event, int *gamestarter);
void if_click_quit(sfRenderWindow *window, sfEvent event, int *gamestarted);
void if_click_play(sfRenderWindow *window, sfEvent event, int *gameStarted);

#endif /* !GAME_JAM_H_ */
