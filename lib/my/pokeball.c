/*
** EPITECH PROJECT, 2020
** pokeball.c
** File description:
** manage with pokeball
*/

#include "../../include/my_hunter.h"

t_ball create_ball(t_ball ball, t_poke poke)
{
    ball.Sball = sfSprite_create();
    ball.Tball2 = sfTexture_createFromFile("picture/ball2.png", NULL);
    ball.Tball3 = sfTexture_createFromFile("picture/ball3.png", NULL);
    ball.Tball4 = sfTexture_createFromFile("picture/ball4.png", NULL);
    sfSprite_setPosition(ball.Sball, sfSprite_getPosition(poke.Spoke));
    return (ball);
}

t_list change_texture_ball(t_list list, t_ball ball, int i)
{
    if (i == 1)
        sfSprite_setTexture(ball.Sball, ball.Tball2, 1);
    if (i == 2)
        sfSprite_setTexture(ball.Sball, ball.Tball3, 1);
    if (i == 3)
        sfSprite_setTexture(ball.Sball, ball.Tball4, 1);
    sfRenderWindow_drawSprite(list.game, ball.Sball, NULL);
    return (list);
}

void display_ball(t_list list, t_poke poke1, t_poke poke2)
{
    t_ball ball = create_ball(ball, poke1);

    for (int i = 1; i != 4; i += 1) {
        sfRenderWindow_clear(list.game, sfBlack);
        sfRenderWindow_drawSprite(list.game, list.back.Sback, NULL);
        list = change_texture_ball(list, ball, i);
        sfRenderWindow_drawSprite(list.game, poke2.Spoke, NULL);
        list = set_nbpoke(list);
        sfRenderWindow_display(list.game);
        check_clock(0.03);
    }
}
