/*
** EPITECH PROJECT, 2019
** Matchsticks
** File description:
** Matchsticks
*/

#include "include/my.h"

void shorten_removerai(t_all *all, int i)
{
    int tmp = 0;
    if (all->vt->tab[all->va->ai_line][i] == ' ' ||
    all->vt->tab[all->va->ai_line][i] == '*'){
        tmp = i - 1;
        if (all->vt->tab[all->va->ai_line][tmp] == '|')
            all->vt->tab[all->va->ai_line][tmp] = ' ';
    }
}

void remover_ai(t_all *all)
{
    for (int a = 0; a < all->va->ai_matches; a++){
        for (int i = 1; i < my_strlen(all->vt->tab[all->va->ai_line]); i++)
            shorten_removerai(all, i);
    }
}

void print_ai(t_all *all)
{
    my_putstr("AI removed ");
    my_put_nbr(all->va->ai_matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(all->va->ai_line);
    my_putchar('\n');
}

void ai_turn(t_all *all)
{
    int tmp = all->va->nb_lines + 1;
    int tmp1 = 0;
    int tmp2 = 0;
    for (int x = all->va->ai_line; count_sticks(all, x) == 0;){
        all->va->ai_line = rand() % tmp;
        x = all->va->ai_line;
    }
    if (count_sticks(all, all->va->ai_line) == 0)
        ai_turn(all);
    tmp1 = count_sticks(all, all->va->ai_line);
    if (tmp1 > all->va->removable_match)
        tmp1 = all->va->removable_match;
    all->va->ai_matches = rand() % tmp1;
    if (all->va->ai_matches == 0)
        all->va->ai_matches++;
    print_ai(all);
    all->va->ai_wins++;
}