/*
** EPITECH PROJECT, 2020
** menu
** File description:
** handle menu
*/

#include "../../include/my_hunter.h"

t_back create_back(t_back back)
{
    back.Tback = sfTexture_createFromFile("picture/background.png", NULL);
    back.Sback = sfSprite_create();
    back.size = sfTexture_getSize(back.Tback);
    sfSprite_setTexture(back.Sback, back.Tback, 1);
    return (back);
}

sfText *create_playB(sfText *playB, sfVideoMode video)
{
    sfFont *font = sfFont_createFromFile("picture/Shiny_Signature.ttf");
    int size = video.width / 20;
    sfVector2f playB_pos = {video.width / 2 - size * 1.5, video.height / 2};

    playB = sfText_create();
    sfText_setString(playB, "PLAY");
    sfText_setFont(playB, font);
    sfText_setCharacterSize(playB, size);
    sfText_setPosition(playB, playB_pos);
    sfText_setColor(playB, sfBlack);
    return (playB);
}

int check_click(sfRenderWindow *menu, sfText *playB)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(menu);
    sfVector2f playB_pos = sfText_getPosition(playB);
    unsigned int playB_size = sfText_getCharacterSize(playB);

    if (sfMouse_isButtonPressed(sfMouseLeft) == 0)
        return (0);
    if (mouse_pos.x < playB_pos.x || mouse_pos.y < playB_pos.y || mouse_pos.x \
    > playB_pos.x + playB_size * 2.4 || mouse_pos.y > playB_pos.y + playB_size)
        return (0);
    return (1);
}

int display_menu(void)
{
    t_back back = create_back(back);
    sfVideoMode video = {back.size.x, back.size.y, 32};
    sfText *playB = create_playB(playB, video);
    sfRW *menu = sfRenderWindow_create(video, "Menu My Hunter", sfClose, NULL);
    sfEvent event;

    while (sfRenderWindow_isOpen(menu)) {
        while (sfRenderWindow_pollEvent(menu, &event)) {
            if (check_click(menu, playB)) {
                sfRenderWindow_destroy(menu);
                return (1);
            }
            if (event.type == sfEvtClosed)
                break;
        }
        sfRenderWindow_clear(menu, sfBlack);
        sfRenderWindow_drawSprite(menu, back.Sback, NULL);
        sfRenderWindow_drawText(menu, playB, NULL);
        sfRenderWindow_display(menu);
    }
    sfRenderWindow_destroy(menu);
    return (0);
}
