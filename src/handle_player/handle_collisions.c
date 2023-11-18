/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** handle_collisions
*/

#include "../../include/game_jam.h"

int checkCollision(sfVector2f position, sfImage* collisionMap)
{
    // Get the color of the pixel at the intended position
    sfColor pixelColor = sfImage_getPixel(collisionMap, (unsigned int)position.x, (unsigned int)position.y);
    
    // Check if the pixel color represents a wall (e.g., if it's black)
    if (pixelColor.r == 0 && pixelColor.g == 0 && pixelColor.b == 0) {
        // Collision detected
        return 1;
    }
    // No collision
    return 0;
}