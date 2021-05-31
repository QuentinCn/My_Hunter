/*
** EPITECH PROJECT, 2020
** end
** File description:
** manage with end
*/

#include "../../include/my_hunter.h"

t_button manage_loop(t_back back, t_button button)
{
    sfRenderWindow_drawSprite(button.menu, back.Sback, NULL);
    sfRenderWindow_drawText(button.menu, button.scoreB, NULL);
    sfRenderWindow_drawText(button.menu, button.high_scoreB, NULL);
    sfRenderWindow_drawText(button.menu, button.againB, NULL);
    sfRenderWindow_drawText(button.menu, button.exitB, NULL);
    if (check_click(button.menu, button.againB))
        button.status = 1;
    if (check_click(button.menu, button.exitB))
        button.status = 2;
    return (button);
}

t_button create_list_button(sfVideoMode video, int score, int high_score)
{
    sfText *scoreB = create_scoreB(scoreB, video, score);
    sfText *high_scoreB = create_high_scoreB(high_scoreB, video, high_score);
    sfText *againB = create_againB(againB, video);
    sfText *exitB = create_exitB(exitB, video);
    sfRW *menu = sfRenderWindow_create(video, "Menu My Hunter", sfClose, NULL);
    t_button button = {scoreB, high_scoreB, againB, exitB, 0, menu};

    return (button);
}

int display_end(int score, int high_score)
{
    t_back back = create_back(back);
    sfVideoMode video = {back.size.x, back.size.y, 32};
    sfEvent event;
    t_button button = create_list_button(video, score, high_score);

    while (sfRenderWindow_isOpen(button.menu)) {
        while (sfRenderWindow_pollEvent(button.menu, &event)) {
            if (event.type == sfEvtClosed)
                break;
        }
        sfRenderWindow_clear(button.menu, sfBlack);
        button = manage_loop(back, button);
        if (button.status == 1)
            return (1);
        if (button.status == 2)
            return (0);
        sfRenderWindow_display(button.menu);
    }
    sfRenderWindow_destroy(button.menu);
    return (0);
}
