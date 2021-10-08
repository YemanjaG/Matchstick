/*
** EPITECH PROJECT, 2019
** Matchsticks
** File description:
** Matchsticks
*/

#include "include/my.h"

void shorten_remover(t_all *all, int i)
{
    int tmp = 0;
    if (all->vt->tab[all->va->lineR][i] == ' '
    || all->vt->tab[all->va->lineR][i] == '*'){
        tmp = i - 1;
        if (all->vt->tab[all->va->lineR][tmp] == '|')
            all->vt->tab[all->va->lineR][tmp] = ' ';
    }
}

void remover(t_all *all)
{
    int tmp = 0;
    for (int a = 0; a < all->va->matchesR; a++){
        for (int i = 1; i < my_strlen(all->vt->tab[all->va->lineR]); i++){
            shorten_remover(all, i);
        }
    }
}

void shorten_player_turn(t_all *all)
{
    my_putstr("Player removed ");
    my_put_nbr(all->va->matchesR);
    my_putstr(" match(es) from line ");
    my_put_nbr(all->va->lineR);
    my_putchar('\n');
}

int player_turn(t_all *all)
{
    my_putstr("Line: ");
    all->va->buff1 = get_next_line(0);
    if (all->va->buff1 == 0){
        return 1;
    }
    if (line_player(all) == 1){
        return 1;
    }
    my_putstr("Matches: ");
    all->va->buff2 = get_next_line(0);
    if (all->va->buff2 == 0)
        return 1;
    if (matches_player(all) == 1)
        return 1;
    shorten_player_turn(all);
    remover(all);
    all->va->human_wins++;
    return 0;
}