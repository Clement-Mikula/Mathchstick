/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-clement.mikula
** File description:
** ia
*/

#include <stdlib.h>
#include "my.h"

void print_ia_turn(int line, int matche)
{
    my_putchar('\n');
    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(matche);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int ia_line(game_t *game)
{
    int line = random() % (game->line + 1);
    if (line == 0)
        line += 1;
    game->update_line = line;
    find_match_position(game);
    return line;
}

void ia_turn(game_t *game)
{
    int line = ia_line(game);
    if (game->match_pos[0] == -1) {
        ia_turn(game);
        return;
    }
    int length = 0;
    for (int i = 0; game->match_pos[i] != -1; i++, ++length);
    int matche = random() % game->max_matches;
    if (matche > length) {
        ia_turn(game);
        return;
    }
    if (matche == 0)
        matche = 1;
    find_match_position(game);
    ia_update_map(line, matche, game);
    print_ia_turn(line, matche);
}

void ia_update_map(int line, int matche, game_t *game)
{
    game->update_line = line;
    find_match_position(game);
    int length = 0;
    for (int i = 0; game->match_pos[i] != -1; i++, length++)
        ;
    for (int i = matche; i > 0; i--)
        game->map[line][game->match_pos[length - i]] = ' ';
}

int check_ia_win(game_t *game)
{
    int nb_matche = 0;
    int max_cols = game->line * 2 + 1;

    for (int i = 0; i < game->line + 1; i++)
        for (int j = 0; j < max_cols; j++)
            if (game->map[i][j] == '|')
                nb_matche++;
    if (nb_matche == 0)
    {
        my_putstr("You lost, too bad...\n");
        return 2;
    }
    else
        return 0;
}