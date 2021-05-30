/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-clement.mikula
** File description:
** get_arguments
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int get_line(game_t *game, int k)
{
    if (k)
        my_putstr("Your turn:\n");
    my_putstr("Line: ");
    char *word = malloc(sizeof(char) * 100);
    size_t size;
    if (getline(&word, &size, stdin) == -1)
        return -1;
    if (error_ascii_getline(word))
    {
        return get_line(game, 0);
    }
    int line = my_getnbr(word);
    line /= 10;
    if (error_line(game, line))
    {
        return get_line(game, 0);
    }
    game->update_line = line;
    return 0;
}

int error_max_matches(game_t *game, int match)
{
    if (match > game->max_matches)
    {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->max_matches);
        my_putstr(" matches per turn\n");
        return error_matche(game);
    }
    return 0;
}

int get_match(game_t *game)
{
    my_putstr("Matches: ");
    char *word = malloc(sizeof(char) * 100);
    size_t size;
    if (getline(&word, &size, stdin) == -1)
        return -1;
    if (error_ascii_getline(word))
        return error_matche(game);
    if (my_getnbr(word) == 0)
    {
        my_putstr("Error: you have to remove at least one match\n");
        return error_matche(game);
    }
    int match = my_getnbr(word);
    match /= 10;
    error_max_matches(game, match);

    game->update_matches = match;
    return 0;
}