/*
** EPITECH PROJECT, 2021
** mathsticks
** File description:
** my
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_

typedef struct game_s
{
    int line;
    int max_matches;
    char **map;
    int update_line;
    int update_matches;
    int *match_pos;
} game_t;

void print_map(char **map, int max_line);
char *init_game(int line);
int error_line(game_t *game, int line);
int error_ascii_getline(char *word);
int get_line(game_t *game, int k);
int get_match(game_t *game);
void find_match_position(game_t *game);
void print_player_turn(game_t *game);
void update_map(game_t *game);
void ia_update_map(int line, int matche, game_t *game);
void print_ia_turn(int line, int matche);
void ia_turn(game_t *game);
int check_player_win(game_t *game);
int check_ia_win(game_t *game);
int error_matche(game_t *game);
int player_turn(game_t *game);
int game_loop(game_t *game);
int game(int argc, char const *argv[]);
int error_handling(int argc, char const *argv[]);
int ia_line(game_t *game);
int ia_matches(game_t *game);

#endif /* !MATCHSTICK_H_ */