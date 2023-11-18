/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** calculate_angle
*/

#include "../../include/game_jam.h"
#include <math.h>

float calculateAngle(sfVector2f point1, sfVector2f point2) {
    return atan2(point2.y - point1.y, point2.x - point1.x) * 180 / M_PI;
}