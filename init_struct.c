/*
** EPITECH PROJECT, 2019
** Matchsticks
** File description:
** Matchsticks
*/

#include "include/my.h"

t_va *init_variable(char** av, int ac)
{
    t_va *va = malloc(sizeof(t_va));
    va->nb_lines = 0;
    va->removable_match = 0;
    va->largeur = 5;
    va->hauteur = 4;
    va->line = 1;
    va->col = 1;
    va->buff1 = malloc(sizeof(char) * 1000);
    va->buff2 = malloc(sizeof(char) * 1000);
    va->lineR = 0;
    va->matchesR = 0;
    va->ai_line = 0;
    va->ai_matches = 0;
    va->human_wins = 0;
    va->ai_wins = 0;
    va->copy_ac = ac;
    va->copy_av = av;
    return va;
}

t_ut *init_tab(char** av, int ac)
{
    t_ut *vt = malloc(sizeof(t_ut));
    vt->tab = malloc(sizeof(char*) * transform(av[1]) + 4 + 1000);
    for (int i = 0; i < transform(av[1]) + 4; i++){
        vt->tab[i] = malloc(sizeof(char) * transform(av[1]) * 4 + 1000);
    }
    return vt;
}

t_all *init_all(char** av, int ac)
{
    t_all *all = malloc(sizeof(t_all));
    all->va = init_variable(av, ac);
    all->vt = init_tab(av, ac);
    all->stahp = 0;
    return all;
}