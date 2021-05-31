/*
** EPITECH PROJECT, 2020
** hoho
** File description:
** manage hoho
*/

#include "../../include/my_hunter.h"

sfVector2f place_hoho(sfVideoMode video, t_poke hoho)
{
    sfVector2f start;

    srand(time(NULL));
    start.y = video.height + hoho.size.x * 45;
    start.x = rand() % 1000;
    while (start.x > video.width - 150 || start.x < 0)
        start.x = rand() % 1000;
    return (start);
}

t_poke create_hoho(t_poke hoho, sfVideoMode video)
{
    hoho.Spoke = sfSprite_create();
    hoho.Tpoke1 = sfTexture_createFromFile("picture/hoho1.png", NULL);
    hoho.Tpoke2 = sfTexture_createFromFile("picture/hoho2.png", NULL);
    hoho.size.x = 2.5;
    hoho.size.y = 2.5;
    if (hoho.mov.y <= -12)
        hoho.mov.y -= 7;
    else
        hoho.mov.y = -20;
    hoho.mov.x = 0;
    sfSprite_setPosition(hoho.Spoke, place_hoho(video, hoho));
    sfSprite_setScale(hoho.Spoke, hoho.size);
    return (hoho);
}

t_poke move_hoho(t_poke hoho, sfVideoMode video)
{
    sfSprite_move(hoho.Spoke, hoho.mov);
    return (hoho);
}

int hit_hoho(sfRenderWindow *game, t_poke hoho)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game);
    sfVector2f hoho_pos = sfSprite_getPosition(hoho.Spoke);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse_pos.x >= hoho_pos.x && mouse_pos.y >= hoho_pos.y \
        && mouse_pos.x <= hoho_pos.x + hoho.size.x * 65 && mouse_pos.y \
        <= hoho_pos.y + hoho.size.y * 40)
            return (1);
    }
    return (0);
}

t_list anime_hoho(sfVideoMode video, t_list list, int i)
{
    if (i == 1 || i == 3)
        sfSprite_setTexture(list.hoho.Spoke, list.hoho.Tpoke1, 1);
    if (i == 2 || i == 4)
        sfSprite_setTexture(list.hoho.Spoke, list.hoho.Tpoke2, 1);
    list.hoho = move_hoho(list.hoho, video);
    sfRenderWindow_drawSprite(list.game, list.back.Sback, NULL);
    sfRenderWindow_drawSprite(list.game, list.hoho.Spoke, NULL);
    if (hit_hoho(list.game, list.hoho)) {
        list.score += 1;
        list.hoho = create_hoho(list.hoho, video);
    }
    if (sfSprite_getPosition(list.hoho.Spoke).y < 0) {
        list.hoho = create_hoho(list.hoho, video);
    }
    return (anime_pika(video, list, i));
}
