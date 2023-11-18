/*
** EPITECH PROJECT, 2023
** workspace.json
** File description:
** display buttons.c
*/

#include "../../include/game_jam.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

void display_resume_button(sfRenderWindow *window, sfVector2f scale, sfVector2f pos)
{
    sfTexture *resume = sfTexture_createFromFile("assets/resume_menu/resume.png", NULL);
    sfSprite *resu_sprite = sfSprite_create();
    
    sfSprite_setTexture(resu_sprite, resume, sfTrue);
    sfSprite_setScale(resu_sprite, scale);
    sfSprite_setPosition(resu_sprite, pos);
    sfRenderWindow_drawSprite(window, resu_sprite, NULL);
    
    sfSprite_destroy(resu_sprite);
    sfTexture_destroy(resume);
}

void display_restart_button(sfRenderWindow *window, sfVector2f scale, sfVector2f pos)
{
    sfTexture *restart = sfTexture_createFromFile("assets/resume_menu/restart.png", NULL);
    sfSprite *rest_sprite = sfSprite_create();
    
    sfSprite_setTexture(rest_sprite, restart, sfTrue);
    sfSprite_setScale(rest_sprite, scale);
    sfSprite_setPosition(rest_sprite, pos);
    sfRenderWindow_drawSprite(window, rest_sprite, NULL);

    sfSprite_destroy(rest_sprite);
    sfTexture_destroy(restart);
}

void display_menu_button(sfRenderWindow *window, sfVector2f scale, sfVector2f pos)
{
    sfTexture *menu = sfTexture_createFromFile("assets/resume_menu/restart.png", NULL);
    sfSprite *menu_sprite = sfSprite_create();
    
    sfSprite_setTexture(menu_sprite, menu, sfTrue);
    sfSprite_setScale(menu_sprite, scale);
    sfSprite_setPosition(menu_sprite, pos);
    sfRenderWindow_drawSprite(window, menu_sprite, NULL);

    sfSprite_destroy(menu_sprite);
    sfTexture_destroy(menu);
}