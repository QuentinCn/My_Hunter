/*
** EPITECH PROJECT, 2020
** create_Button
** File description:
** create button for end.c
*/

#include "../../include/my_hunter.h"

sfText *create_scoreB(sfText *scoreB, sfVideoMode video, int score)
{
    sfFont *font = sfFont_createFromFile("picture/Shiny_Signature.ttf");
    int size = video.width / 20;
    sfVector2f scoreB_pos = {video.width / 2 - size * 2.75, 1.5 * \
    video.height / 6};

    scoreB = sfText_create();
    sfText_setString(scoreB, find_nb_click(1, score));
    sfText_setFont(scoreB, font);
    sfText_setCharacterSize(scoreB, size);
    sfText_setPosition(scoreB, scoreB_pos);
    sfText_setColor(scoreB, sfBlack);
    return (scoreB);
}

sfText *create_high_scoreB(sfText *high_scoreB, sfVideoMode video, \
int high_score)
{
    sfFont *font = sfFont_createFromFile("picture/Shiny_Signature.ttf");
    int size = video.width / 20;
    sfVector2f high_scoreB_pos = {video.width / 2 - size * 3.75, 2.5 * \
    video.height / 6};

    high_scoreB = sfText_create();
    sfText_setString(high_scoreB, find_nb_click(2, high_score));
    sfText_setFont(high_scoreB, font);
    sfText_setCharacterSize(high_scoreB, size);
    sfText_setPosition(high_scoreB, high_scoreB_pos);
    sfText_setColor(high_scoreB, sfBlack);
    return (high_scoreB);
}

sfText *create_againB(sfText *againB, sfVideoMode video)
{
    sfFont *font = sfFont_createFromFile("picture/Shiny_Signature.ttf");
    int size = video.width / 20;
    sfVector2f againB_pos = {video.width / 2 - size * 3, 3.5 * \
    video.height / 6};

    againB = sfText_create();
    sfText_setString(againB, "PLAY AGAIN");
    sfText_setFont(againB, font);
    sfText_setCharacterSize(againB, size);
    sfText_setPosition(againB, againB_pos);
    sfText_setColor(againB, sfBlack);
    return (againB);
}

sfText *create_exitB(sfText *exitB, sfVideoMode video)
{
    sfFont *font = sfFont_createFromFile("picture/Shiny_Signature.ttf");
    int size = video.width / 20;
    sfVector2f exitB_pos = {video.width / 2 - size * 1.5, 4.5 * \
    video.height / 6};

    exitB = sfText_create();
    sfText_setString(exitB, "EXIT");
    sfText_setFont(exitB, font);
    sfText_setCharacterSize(exitB, size);
    sfText_setPosition(exitB, exitB_pos);
    sfText_setColor(exitB, sfBlack);
    return (exitB);
}
