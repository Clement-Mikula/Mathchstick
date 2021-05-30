/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-clement.mikula
** File description:
** init_map
*/

#include <stdlib.h>
#include "my.h"

static void game_first_line(map_t *map)
{
    for (int i = 0; i < (map->nb_space + 2); i++)
    {
        map->game[map->nb_game] = '*';
        map->nb_game++;
    }
    map->game[map->nb_game] = '\n';
    map->nb_game++;
}

static void game_last_line(map_t *map, int line)
{
    map->nb_space = (line * 2) - 1;
    for (int i = 0; i < (map->nb_space + 2); i++)
    {
        map->game[map->nb_game] = '*';
        map->nb_game++;
    }

    map->game[map->nb_game] = '\n';
    map->nb_game++;
    map->game[map->nb_game] = '\0';
    map->nb_game++;
}

static void game_middle_line(map_t *map)
{
    map->game[map->nb_game] = '*';
    map->nb_game++;

    for (int i = 0; i < map->nb_space / 2; i++) {
        map->game[map->nb_game] = ' ';
        map->nb_game++;
    }
    for (int i = 0; i < map->nb_stick; i++) {
        map->game[map->nb_game] = '|';
        map->nb_game++;
    }
    for (int i = 0; i < map->nb_space / 2; i++) {
        map->game[map->nb_game] = ' ';
        map->nb_game++;
    }
}

static void game_change_value(map_t *map)
{
    map->nb_stick += 2;
    map->nb_space -= 2;
    map->game[map->nb_game] = '*';
    map->nb_game++;
    map->game[map->nb_game] = '\n';
    map->nb_game++;
}

char *init_game(int line)
{
    map_t map;
    map.nb_game = 0;
    map.nb_stick = 1;
    map.game = malloc(sizeof(char) * ((line + 2) * (line * 2 + 1)) * 2);
    map.nb_space = (line * 2) - 1;

    game_first_line(&map);
    for (int i = 0; i < line; i++)
    {
        game_middle_line(&map);
        game_change_value(&map);
    }
    game_last_line(&map, line);
    return map.game;
}