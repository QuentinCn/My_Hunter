/*
** EPITECH PROJECT, 2020
** time
** File description:
** manage time
*/

#include "../../include/my_hunter.h"

int check_clock(float sec)
{
    sfClock *clock;
    sfTime one_s = sfSeconds(sec);
    float f_one_s = sfTime_asSeconds(one_s);
    float time;

    clock = sfClock_create();
    time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    while (time < f_one_s)
        time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    return (0);
}
