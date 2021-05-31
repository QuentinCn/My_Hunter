/*
** EPITECH PROJECT, 2020
** main
** File description:
** main my_hunter
*/

#include "include/my_hunter.h"

void info_my_hunter(void)
{
    my_putstr("Welcome !\nThe goal of this game is to capture the most ");
    my_putstr("pokemon possible by clicking on them.\nFor that you will have ");
    my_putstr("25 pokeballs.\nNow that you know everything let's go and ");
    my_putstr("catch them all !!\n");
}

int main(int ac, char **av)
{
    if (ac == 1)
        my_hunter();
    if (ac == 2 && av[1][1] == 'h')
        info_my_hunter();
    return (0);
}
