/*
** EPITECH PROJECT, 2020
** cursor
** File description:
** manage cursor
*/

#include "../../include/my_hunter.h"

char *find_nb_click(int info, int nb)
{
    char *nbr[27] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", \
    "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", \
    "23", "24", "25", 0};
    char *nbr2[27] = {"SCORE = 0", "SCORE = 1", "SCORE = 2", "SCORE = 3", \
    "SCORE = 4", "SCORE = 5", "SCORE = 6", "SCORE = 7", "SCORE = 8", \
    "SCORE = 9", "SCORE = 10", "SCORE = 11", "SCORE = 12", "SCORE = 13", \
    "SCORE = 14", "SCORE = 15", "SCORE = 16", "SCORE = 17", "SCORE = 18", \
    "SCORE = 19", "SCORE = 20", "SCORE = 21", "SCORE = 22", "SCORE = 23", \
    "SCORE = 24", "SCORE = 25", 0};
    char *nbr3[27] = {"HIGH SCORE = 0", "HIGH SCORE = 1", "HIGH SCORE = 2", \
    "HIGH SCORE = 3", "HIGH SCORE = 4", "HIGH SCORE = 5", "HIGH SCORE = 6", \
    "HIGH SCORE = 7", "HIGH SCORE = 8", "HIGH SCORE = 9", "HIGH SCORE = 10", \
    "HIGH SCORE = 11", "HIGH SCORE = 12", "HIGH SCORE = 13", "HIGH SCORE = 14"\
    , "HIGH SCORE = 15", "HIGH SCORE = 16", "HIGH SCORE = 17", \
    "HIGH SCORE = 18", "HIGH SCORE = 19", "HIGH SCORE = 20", "HIGH SCORE = 21"\
    , "HIGH SCORE = 22", "HIGH SCORE = 23", "HIGH SCORE = 24", \
    "HIGH SCORE = 25", 0};
    char **nbr4[4] = {nbr, nbr2, nbr3, 0};

    return (nbr4[info][nb]);
}

t_cursor create_cursor(t_cursor cursor)
{
    cursor.Tcursor = sfTexture_createFromFile("picture/reticule.png", NULL);
    cursor.Scursor = sfSprite_create();
    cursor.size.x = 0.2;
    cursor.size.y = 0.2;
    sfSprite_setTexture(cursor.Scursor, cursor.Tcursor, 1);
    return (cursor);
}

t_list set_cursor(t_list list)
{
    sfVector2f pos;

    pos.x = sfMouse_getPositionRenderWindow(list.game).x - 50;
    pos.y = sfMouse_getPositionRenderWindow(list.game).y - 50;
    sfSprite_setPosition(list.cursor.Scursor, pos);
    sfSprite_setScale(list.cursor.Scursor, list.cursor.size);
    sfRenderWindow_setMouseCursorVisible(list.game, 0);
    sfRenderWindow_drawSprite(list.game, list.cursor.Scursor, NULL);
    return (list);
}

t_nbpoke create_nbpoke(t_nbpoke nbpoke, sfVideoMode video)
{
    nbpoke.Tnbpoke = sfTexture_createFromFile("picture/nbpokeball.png", NULL);
    nbpoke.Snbpoke = sfSprite_create();
    nbpoke.nb = sfText_create();
    nbpoke.pos.x = 0;
    nbpoke.pos.y = 0;
    nbpoke.size.x = 1;
    nbpoke.size.y = 1;
    nbpoke.size_nb = nbpoke.size.x * 75;
    nbpoke.nb_pos.x = 0 + nbpoke.size.x * 108;
    nbpoke.nb_pos.y = 0;
    nbpoke.font = sfFont_createFromFile("picture/Shiny_Signature.ttf");
    sfSprite_setScale(nbpoke.Snbpoke, nbpoke.size);
    sfSprite_setPosition(nbpoke.Snbpoke, nbpoke.pos);
    sfSprite_setTexture(nbpoke.Snbpoke, nbpoke.Tnbpoke, 1);
    return (nbpoke);
}

t_list set_nbpoke(t_list list)
{
    sfText_setString(list.nbpoke.nb, find_nb_click(0, list.nb_click));
    sfText_setFont(list.nbpoke.nb, list.nbpoke.font);
    sfText_setCharacterSize(list.nbpoke.nb, list.nbpoke.size_nb);
    sfText_setPosition(list.nbpoke.nb, list.nbpoke.nb_pos);
    sfText_setColor(list.nbpoke.nb, sfBlack);
    sfRenderWindow_drawText(list.game, list.nbpoke.nb, NULL);
    sfRenderWindow_drawSprite(list.game, list.nbpoke.Snbpoke, NULL);
    return (set_cursor(list));
}
