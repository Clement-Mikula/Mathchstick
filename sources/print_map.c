/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-clement.mikula
** File description:
** main
*/

#include "my.h"

void print_map(char **map, int max_line)
{
    for (int i = 0; i < max_line; i++)
    {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}