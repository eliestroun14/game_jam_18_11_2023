/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ghost_init
*/

#include "../../include/game_jam.h"

void initialize_ghost(ghost_t *ghost, sfTexture *ghostTexture)
{
    ghost->sprite = sfSprite_create();
    sfSprite_setTexture(ghost->sprite, ghostTexture, sfTrue);

    // Set initial ghost position
    sfVector2f ghostPosition = {
        (float)(rand() % (int)(1000 - sfSprite_getLocalBounds(ghost->sprite).width)),
        (float)(rand() % (int)(838 - sfSprite_getLocalBounds(ghost->sprite).height))
    };

    sfSprite_setPosition(ghost->sprite, ghostPosition);

    // Set initial ghost velocity (adjust speed as needed)
    ghost->velocity.x = 1.5f;
    ghost->velocity.y = 1.5f;
}

void update_ghost(ghost_t *ghost, sfVector2f playerPosition)
{
    // Calculate direction vector from ghost to player
    sfVector2f direction;
    direction.x = playerPosition.x - sfSprite_getPosition(ghost->sprite).x;
    direction.y = playerPosition.y - sfSprite_getPosition(ghost->sprite).y;

    // Normalize direction
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction.x /= length;
    direction.y /= length;

    // Update ghost's position based on direction (adjust speed by multiplying with direction)
    sfVector2f ghostPosition = sfSprite_getPosition(ghost->sprite);
    ghostPosition.x += ghost->velocity.x * direction.x;
    ghostPosition.y += ghost->velocity.y * direction.y;

    // Update ghost's position
    sfSprite_setPosition(ghost->sprite, ghostPosition);
}