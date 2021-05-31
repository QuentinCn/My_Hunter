/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main fonction of the game
*/

#include "include/my_hunter.h"

int launch_play(int score, int high_score)
{
    score = display_game();
    if (score > high_score)
        high_score = score;
    if (display_end(score, high_score))
        launch_play(score, high_score);
    return (0);
}

int my_hunter(void)
{
    sfMusic *match_music = sfMusic_createFromFile("picture/match_music.ogg");
    int score = 0;
    int high_score = 0;

    sfMusic_setLoop(match_music, 1);
    sfMusic_setVolume(match_music, 5);
    sfMusic_play(match_music);
    if (display_menu())
        launch_play(score, high_score);
    sfMusic_destroy(match_music);
    return  (0);
}
