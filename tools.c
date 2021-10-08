/*
** EPITECH PROJECT, 2019
** Matchsticks
** File description:
** Matchsticks
*/

#include "include/my.h"

int str_to_int(char* str)
{
    int val = 0;
    for (str; *str; str++){
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        } else
            return (val);
    }
    return (val);
}

void set_variables(t_all *all)
{
    all->va->largeur = 2 * all->va->nb_lines + 1;
    all->va->hauteur = all->va->nb_lines + 2;
    all->stahp = 1;
}

void clean_buff(t_all *all, int decider)
{
    if (decider == 1){
        all->va->buff1 = malloc(sizeof(char) * 10);
    }
    else if (decider == 2){
        all->va->buff2 = malloc(sizeof(char) * 10);
    }
}

int count_sticks(t_all *all, int here)
{
    int ret = 0;
    for (int i = 0; i <= my_strlen(all->vt->tab[here]); i++){
        if (all->vt->tab[here][i] == '|')
            ret++;
    }
    return ret;
}