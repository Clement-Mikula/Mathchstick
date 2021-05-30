/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-clement.mikula
** File description:
** main
*/

#include <stdlib.h>
#include <string.h> //strtok
#include "my.h"

void find_match_position(game_t *game)
{
    int k = 0;

    for (int j = 0; game->map[game->update_line][j] != '\0'; j++)
    {
        if (game->map[game->update_line][j] == '|')
        {
            game->match_pos[k] = j;
            k++;
        }
    }
    game->match_pos[k] = -1;
}

void update_map(game_t *game)
{
    int length = 0;
    for (int i = 0; game->match_pos[i] != -1; i++, length++)
        ;
    for (int i = game->update_matches; i > 0; i--)
    {
        if (game->update_matches > length)
        {
            my_putstr("Error: not enough matches on this line\n");
            error_matche(game);
            return;
        }
        else {
            game->map[game->update_line][game->match_pos[length - i]] = ' ';
        }
    }
    print_player_turn(game);
}

int game_loop(game_t *game)
{
    while (1)
    {
        print_map(game->map, game->line + 2);
        if (check_player_win(game) == 1)
            return 1;
        if (player_turn(game) == -1)
            return 0;
        print_map(game->map, game->line + 2);
        if (check_ia_win(game) == 2)
            return 2;
        ia_turn(game);
    }
}

int game(int argc, char const *argv[])
{
    game_t game;
    game.line = my_getnbr(argv[1]);
    game.max_matches = my_getnbr(argv[2]);
    char *basemap = init_game(game.line);
    game.map = my_str_to_word_array(basemap, '\n');
    free(basemap);
    game.match_pos = malloc(sizeof(int) * 100);
    int end = game_loop(&game);
    return end;
}

int main(int argc, char const *argv[])
{
    if (error_handling(argc, argv) == 1)
        return 84;
    int end = game(argc, argv);
    return end;
}