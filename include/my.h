/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** contains all my headers
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#define READ_SIZE 10

typedef struct ultimate_variable
{
    int nb_lines;
    int removable_match;
    int largeur;
    int hauteur;
    int line;
    int col;
    int lineR;
    int matchesR;
    char *buff1;
    char *buff2;
    int ai_line;
    int ai_matches;
    int ai_wins;
    int human_wins;
    int copy_ac;
    char **copy_av;
}t_va;

typedef struct ultimate_tab
{
    char** tab;
}t_ut;

typedef struct ultimate_all
{
    t_va *va;
    t_ut *vt;
    int stahp;
}t_all;

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int my_put_nbr(int nb);
char my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strupcase(char *str);
int main(int ac, char** av);
int my_show_word_array(char * const *tab);
int set_sign(char const *str);
int transform(char const *str);
int separator(char c);
char *my_strdup(char const *src);
t_all *init_all(char** av, int ac);
t_ut *init_tab(char** av, int ac);
t_va *init_variable(char** av, int ac);
void draw_tab(t_all *all);
void draw_tree(t_all *all, int i, int a);
void draw_map(t_all *all);
int str_to_int(char* str);
void set_variables(t_all *all);
void clean_buff(t_all *all, int decider);
int count_sticks(t_all *all, int here);
void remover(t_all *all);
void shorten_remover(t_all *all, int i);
int matches_player(t_all *all);
int shorten_matches_player(t_all *all);
int line_player(t_all *all);
int shorten_line_player(t_all *all);
int player_turn(t_all *all);
void ai_turn(t_all *all);
void remover_ai(t_all *all);
void print_ai(t_all *all);
int game(t_all *all);
char* mr_clean(char* dirty);
char *add_to_str(char* ret, char* add, int i);
char *get_next_line(int fd);

#endif
