/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-clement.mikula
** File description:
** player
*/

#include "my.h"

int player_turn(game_t *game)
{
    my_putchar('\n');
    if (get_line(game, 1) == -1)
        return -1;
    find_match_position(game);
    if (get_match(game) == -1)
        return -1;
    update_map(game);
    return 0;
}

int check_player_win(game_t *game)
{
    int nb_matche = 0;
    int max_cols = game->line * 2 + 1;

    for (int i = 0; i < game->line + 1; i++)
    {
        for (int j = 0; j < max_cols; j++)
        {
            if (game->map[i][j] == '|')
                nb_matche++;
        }
    }
    if (nb_matche == 0)
    {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return 1;
    }
    else
        return 0;
}

void print_player_turn(game_t *game)
{
    my_putstr("Player removed ");
    my_put_nbr(game->update_matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->update_line);
    my_putchar('\n');
}