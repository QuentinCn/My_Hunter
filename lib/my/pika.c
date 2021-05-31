/*
** EPITECH PROJECT, 2020
** pika
** File description:
** manage pikachu
*/

#include "../../include/my_hunter.h"

sfVector2f place_pika(sfVideoMode video, t_poke pika)
{
    sfVector2f start;

    srand(time(NULL));
    start.x = 0 - pika.size.x * 65;
    while (start.y < 2 * (video.height / 3) || \
    start.y > video.height - 80)
        start.y = rand() % 1000;
    return (start);
}

t_poke create_pika(t_poke pika, sfVideoMode video)
{
    pika.Spoke = sfSprite_create();
    pika.Tpoke1 = sfTexture_createFromFile("picture/pika1.png", NULL);
    pika.Tpoke2 = sfTexture_createFromFile("picture/pika2.png", NULL);
    pika.Tpoke3 = sfTexture_createFromFile("picture/pika3.png", NULL);
    pika.Tpoke4 = sfTexture_createFromFile("picture/pika4.png", NULL);
    pika.size.x = 2;
    pika.size.y = 2;
    if (pika.mov.x >= 25)
        pika.mov.x = pika.mov.x + 8;
    else
        pika.mov.x = 25;
    pika.mov.y = 0;
    sfSprite_setPosition(pika.Spoke, place_pika(video, pika));
    sfSprite_setScale(pika.Spoke, pika.size);
    return (pika);
}

t_poke move_pika(t_poke pika, sfVideoMode video)
{
    sfSprite_move(pika.Spoke, pika.mov);
    return (pika);
}

int hit_pika(sfRenderWindow *game, t_poke pika)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game);
    sfVector2f pika_pos = sfSprite_getPosition(pika.Spoke);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse_pos.x >= pika_pos.x && mouse_pos.y >= pika_pos.y \
            && mouse_pos.x <= pika_pos.x + pika.size.x * 65 && mouse_pos.y \
            <= pika_pos.y + pika.size.y * 40)
            return (1);
    }
    return (0);
}

t_list anime_pika(sfVideoMode video, t_list list, int i)
{
    if (i == 1)
        sfSprite_setTexture(list.pika.Spoke, list.pika.Tpoke1, 1);
    if (i == 2)
        sfSprite_setTexture(list.pika.Spoke, list.pika.Tpoke2, 1);
    if (i == 3)
        sfSprite_setTexture(list.pika.Spoke, list.pika.Tpoke3, 1);
    if (i == 4)
        sfSprite_setTexture(list.pika.Spoke, list.pika.Tpoke4, 1);
    list.pika = move_pika(list.pika, video);
    sfRenderWindow_drawSprite(list.game, list.back.Sback, NULL);
    sfRenderWindow_drawSprite(list.game, list.pika.Spoke, NULL);
    if (hit_pika(list.game, list.pika)) {
        list.score += 1;
        list.pika = create_pika(list.pika, video);
    }
    if (sfSprite_getPosition(list.pika.Spoke).x >= video.width) {
        list.pika = create_pika(list.pika, video);
    }
    return (list);
}
