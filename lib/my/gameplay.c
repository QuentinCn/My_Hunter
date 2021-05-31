/*
** EPITECH PROJECT, 2020
** gameplay
** File description:
** manage gameplay
*/

#include "../../include/my_hunter.h"

t_list do_mouse_pressed(t_list list, sfVideoMode video)
{
    if (hit_hoho(list.game, list.hoho)) {
        list.score += 1;
        display_ball(list, list.hoho, list.pika);
        list.hoho = create_hoho(list.hoho, video);
    }
    if (hit_pika(list.game, list.pika)) {
        list.score += 1;
        display_ball(list, list.pika, list.hoho);
        list.pika = create_pika(list.pika, video);
    }
    list.nb_click += 1;
    return (list);
}

t_list change_texture(t_list list, int i)
{
    if (i == 1) {
        sfSprite_setTexture(list.pika.Spoke, list.pika.Tpoke1, 1);
        sfSprite_setTexture(list.hoho.Spoke, list.hoho.Tpoke1, 1);
    } else if (i == 2) {
        sfSprite_setTexture(list.pika.Spoke, list.pika.Tpoke2, 1);
    } else if (i == 3) {
        sfSprite_setTexture(list.pika.Spoke, list.pika.Tpoke3, 1);
        sfSprite_setTexture(list.hoho.Spoke, list.hoho.Tpoke2, 1);
    } else if (i == 4) {
        sfSprite_setTexture(list.pika.Spoke, list.pika.Tpoke4, 1);
    }
    return (list);
}

t_list display_poke(sfVideoMode video, t_list list, int i)
{
    list = change_texture(list, i);
    list.pika = move_pika(list.pika, video);
    list.hoho = move_hoho(list.hoho, video);
    sfRenderWindow_drawSprite(list.game, list.back.Sback, NULL);
    sfRenderWindow_drawSprite(list.game, list.pika.Spoke, NULL);
    sfRenderWindow_drawSprite(list.game, list.hoho.Spoke, NULL);
    if (sfSprite_getPosition(list.pika.Spoke).x >= video.width)
        list.pika = create_pika(list.pika, video);
    if (sfSprite_getPosition(list.hoho.Spoke).y < 0)
        list.hoho = create_hoho(list.hoho, video);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        list = do_mouse_pressed(list, video);
    list = set_nbpoke(list);
    return (list);
}

int play(sfRenderWindow *game, t_back back, sfVideoMode video)
{
    sfEvent event;
    t_poke pika = create_pika(pika, video);
    t_poke hoho = create_hoho(hoho, video);
    t_cursor cursor = create_cursor(cursor);
    t_nbpoke nbpoke = create_nbpoke(nbpoke, video);
    t_list list = {game, pika, hoho, back, cursor, nbpoke, 0};

    for (int i = 1; list.nb_click != 25; i += 1) {
        while (sfRenderWindow_pollEvent(list.game, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_destroy(list.game);
            }
        }
        sfRenderWindow_clear(list.game, sfBlack);
        list = display_poke(video, list, i);
        sfRenderWindow_display(list.game);
        check_clock(0.1);
        if (i == 4)
            i = 0;
    }
    return (list.score);
}

int display_game(void)
{
    t_back back = create_back(back);
    sfVideoMode video = {back.size.x, back.size.y, 32};
    sfRW *game = sfRenderWindow_create(video, "Game My Hunter", sfClose, NULL);
    sfEvent event;
    int score = 0;

    sfRenderWindow_setFramerateLimit(game, 100);
    score = play(game, back, video);
    sfRenderWindow_destroy(game);
    return (score);
}
