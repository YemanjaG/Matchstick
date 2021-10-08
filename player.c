/*
** EPITECH PROJECT, 2019
** Matchsticks
** File description:
** Matchsticks
*/

#include "include/my.h"

int shorten_line_player(t_all *all)
{
    if (all->va->lineR > all->va->nb_lines || all->va->lineR <= 0){
        my_putstr("Error : this line is out of range\n");
        my_putstr("Line: ");
        all->va->buff1 = malloc(sizeof(char) * 10);
        all->va->buff1 = get_next_line(0);
        if (all->va->buff1 == 0)
            return 1;
        all->va->lineR = str_to_int(all->va->buff1);
        line_player(all);
    }
    if (count_sticks(all, all->va->lineR) == 0){
        my_putstr("Error: selected line is empty\n");
        my_putstr("Line: ");
        all->va->buff1 = malloc(sizeof(char) * 10);
        all->va->buff1 = get_next_line(0);
        if (all->va->buff1 == 0)
            return 1;
        all->va->lineR = str_to_int(all->va->buff1);
        line_player(all);
    } return 0;
}

int line_player(t_all *all)
{
    all->va->lineR = str_to_int(all->va->buff1);
    for (int i = 0; all->va->buff1[i] != '\0'; i++){
        if (all->va->buff1[i] > '9' || all->va->buff1[i] < '0'){
            my_putstr("Error: invalid input (positive number expected)\n");
            my_putstr("Line: ");
            i = 0;
            all->va->buff1 = malloc(sizeof(char) * 10);
            all->va->buff1 = get_next_line(0);
            if (all->va->buff1 == 0)
                return 1;
        }
    }
    if (shorten_line_player(all) == 1)
        return 1;
    all->va->lineR = str_to_int(all->va->buff1);
    return 0;
}

int shorten_matches_again(t_all *all)
{
    if (all->va->matchesR > all->va->removable_match){
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(all->va->removable_match);
        my_putstr(" per turn\n");
        clean_buff(all, 1);
        clean_buff(all, 2);
        my_putstr("Line: ");
        all->va->buff1 = get_next_line(0);
        if (all->va->buff1 == 0)
            return 1;
        line_player(all);
        my_putstr("Matches: ");
        all->va->buff2 = get_next_line(0);
        if (all->va->buff2 == 0)
            return 1;
        matches_player(all);
    }
    if (shorten_matches_player(all) == 1)
        return 1;
    return 0;
}

int shorten_matches_player(t_all *all)
{
    if (all->va->matchesR == 0 && str_to_int(all->va->buff2) == 0){
        my_putstr("You have to remove at least one match\n");
        my_putstr("Matches: ");
        all->va->buff2 = malloc(sizeof(char) * 10);
        all->va->buff2 = get_next_line(0);
        if (all->va->buff2 == 0)
            return 1;
        matches_player(all);
    }
    if (all->va->matchesR > count_sticks(all, all->va->lineR)){
        my_putstr("Error: not enough matches on this line\n");
        my_putstr("Matches: ");
        all->va->buff2 = malloc(sizeof(char) * 10);
        all->va->buff2 = get_next_line(0);
        if (all->va->buff2 == 0)
            return 1;
        matches_player(all);
    }
    all->va->matchesR = str_to_int(all->va->buff2);
    return 0;
}

int matches_player(t_all *all)
{
    all->va->matchesR = str_to_int(all->va->buff2);
    for (int i = 0; all->va->buff2[i] != '\0'; i++){
        if (all->va->buff2[i] > '9' || all->va->buff2[i] < '0'){
            my_putstr("Error: invalid input (positive number expected)\n");
            my_putstr("Matches: ");
            i = 0;
            all->va->buff2 = malloc(sizeof(char) * 10);
            all->va->buff2 = get_next_line(0);
            if (all->va->buff2 == 0){
                return 1;
            }
        }
    }
    if (shorten_matches_again(all) == 1)
        return 1;
    return 0;
}