/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** .h of my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

typedef sfTexture sfT;
typedef sfSprite sfS;
typedef sfRenderWindow sfRW;

typedef struct button_info
{
    sfText *scoreB;
    sfText *high_scoreB;
    sfText *againB;
    sfText *exitB;
    int status;
    sfRW *menu;
}t_button;

typedef struct background_info
{
    sfS *Sback;
    sfT *Tback;
    sfVector2u size;
}t_back;

typedef struct pokeball_info
{
    sfS *Sball;
    sfT *Tball1;
    sfT *Tball2;
    sfT *Tball3;
    sfT *Tball4;
    sfT *Tball5;
    sfT *Tball6;
    int size;
}t_ball;

typedef struct pokemon_info
{
    sfS *Spoke;
    sfT *Tpoke1;
    sfT *Tpoke2;
    sfT *Tpoke3;
    sfT *Tpoke4;
    sfVector2f size;
    sfVector2f mov;
}t_poke;

typedef struct nb_poke_info
{
    sfS *Snbpoke;
    sfT *Tnbpoke;
    sfVector2f pos;
    sfVector2f size;
    sfText *nb;
    sfVector2f nb_pos;
    sfFont *font;
    int size_nb;
}t_nbpoke;

typedef struct cursor_info
{
    sfT *Tcursor;
    sfS *Scursor;
    sfVector2f size;
}t_cursor;

typedef struct list_info
{
    sfRenderWindow *game;
    t_poke pika;
    t_poke hoho;
    t_back back;
    t_cursor cursor;
    t_nbpoke nbpoke;
    int nb_click;
    int score;
}t_list;

int display_menu(void);
int my_hunter(void);
t_back create_back(t_back back);
t_list anime_pika(sfVideoMode video, t_list list, int i);
int check_clock(float sec);
int display_game(void);
t_poke create_pika(t_poke pika, sfVideoMode video);
int hit_pika(sfRenderWindow *game, t_poke pika);
int display_end(int score, int high_score);
t_list set_cursor(t_list list);
t_cursor create_cursor(t_cursor cursor);
t_list set_cursor(t_list list);
t_nbpoke create_nbpoke(t_nbpoke nbpoke, sfVideoMode video);
t_list set_nbpoke(t_list list);
char *my_revstr(char *str);
int my_strlen(char *str);
t_poke create_hoho(t_poke hoho, sfVideoMode video);
t_list anime_hoho(sfVideoMode video, t_list list, int i);
int hit_hoho(sfRW *game, t_poke hoho);
int hit_pika(sfRW *game, t_poke pika);
t_poke move_pika(t_poke pika, sfVideoMode video);
t_poke move_hoho(t_poke hoho, sfVideoMode video);
void display_ball(t_list list, t_poke poke1, t_poke poke2);
int check_click(sfRenderWindow *menu, sfText *playB);
sfText *create_againB(sfText *againB, sfVideoMode video);
sfText *create_exitB(sfText *exitB, sfVideoMode video);
t_button manage_loop(t_back back, t_button button);
char *find_nb_click(int info, int nb);
sfText *create_scoreB(sfText *scoreB, sfVideoMode video, int score);
sfText *create_high_scoreB(sfText *high_scoreB, sfVideoMode video, \
int high_score);
sfText *create_againB(sfText *againB, sfVideoMode video);
sfText *create_exitB(sfText *exitB, sfVideoMode video);
void my_putchar(char c);
int my_putstr(char *str);
