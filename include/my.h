/*
** EPITECH PROJECT, 2021
** mathsticks
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

//#include <stdlib.h>
//#include <stdio.h>
//#include <time.h>

typedef struct game_s
{
    int line;
    int max_matches;
    char **map;
    int update_line;
    int update_matches;
    int *match_pos;
} game_t;

typedef struct map_s
{
    int nb_game;
    int nb_stick;
    char *game;
    int nb_space;

} map_t;

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

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char *str, char pars);

#endif /* !MY_H_ */