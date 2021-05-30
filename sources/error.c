/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-clement.mikula
** File description:
** error
*/

#include "my.h"

int error_handling(int argc, char const *argv[])
{
    if (argc != 3)
        return 1;
    if (my_getnbr(argv[1]) < 2 || my_getnbr(argv[1]) > 99)
        return 1;
    if (my_getnbr(argv[2]) < 1)
        return 1;
    else
        return 0;
}

int error_line(game_t *game, int line)
{
    if (line < 1)
    {
        my_putstr("Error: invalid input (positive number expected)\n");
        return 1;
    }
    if (line > game->line || line == 0)
    {
        my_putstr("Error: this line is out of range\n");
        return 1;
    }
    return 0;
}

int error_ascii_getline(char *word)
{
    for (int i = 0; word[i] != '\n'; i++)
    {
        if (word[i] < 48 || word[i] > 57)
        {
            my_putstr("Error: invalid input (positive number expected)\n");
            return 1;
        }
        if (my_strlen(word) > 9)
        {
            my_putstr("Error: invalid input (positive number expected)\n");
            return 1;
        }
    }
    return 0;
}

int error_matche(game_t *game)
{
    if (get_line(game, 0) == -1)
        return -1;
    find_match_position(game);
    if (get_match(game) == -1)
        return -1;
    return 0;
}
