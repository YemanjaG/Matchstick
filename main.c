/*
** EPITECH PROJECT, 2019
** Matchsticks
** File description:
** Matchsticks
*/

#include "include/my.h"

int is_it_over(t_all *all)
{
    for (int i = 0; i < all->va->hauteur; i++){
        for (int a = 0;a <= my_strlen(all->vt->tab[i]); a++){
            if (all->vt->tab[i][a] == '|'){
                return 1;
            }
        }
    }
    return 0;
}

int check_win(t_all *all)
{
    if (str_to_int(all->va->buff1) == 0 ||
    str_to_int(all->va->buff2) == 0){
        return 0;
    }
    else if (all->va->ai_wins < all->va->human_wins){
        my_putstr("You lost, too bad...\n");
        return 2;
    }
    if (all->va->ai_wins >= all->va->human_wins){
        my_putstr("I lost... sniff... but I'll get you next time!!\n");
        return 1;
    }
}

int game(t_all *all)
{
    while (1){
        my_putstr("\nYour turn:\n");
        if (player_turn(all) == 1)
            return 0;
        draw_tab(all);
        if (is_it_over(all) == 0)
            break;
        my_putstr("\nAI's turn ...\n");
        ai_turn(all);
        remover_ai(all);
        draw_tab(all);
        if (is_it_over(all) == 0)
            break;
    }
    return check_win(all);
}

int error_gestion(int ac, char** av)
{
    if (ac != 3){
        return 84;
    }
    if (str_to_int(av[1]) < 2 || str_to_int(av[1]) > 100){
        return 84;
    }
    if (str_to_int(av[2]) < 1){
        return 84;
    }
    return 0;
}

int main(int ac, char** av)
{
    if (error_gestion(ac, av) != 0)
        return error_gestion(ac, av);
    t_all *all = init_all(av, ac);
    all->va->nb_lines = str_to_int(av[1]);
    all->va->removable_match = str_to_int(av[2]);
    set_variables(all);
    draw_map(all);
    draw_tab(all);
    return game(all);
}