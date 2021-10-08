/*
** EPITECH PROJECT, 2019
** Matchsticks
** File description:
** Matchsticks
*/

#include "include/my.h"

void draw_tab(t_all *all)
{
    for (int i = 0; i < all->va->hauteur; i++){
        my_putstr(all->vt->tab[i]);
        my_putchar('\n');
    }
}

void draw_tree(t_all *all, int i, int a)
{
    if (a >= all->va->largeur / 2 - (i - 1)
    && a <= all->va->largeur / 2 + (i - 1))
        all->vt->tab[i][a] = '|';
    else
        all->vt->tab[i][a] = ' ';
}

void shorten_draw_map(t_all *all, int i)
{
    for (int a = 0; a != all->va->largeur; a++){
        if (i == 0
        || a == 0
        || i == all->va->hauteur - 1
        || a == all->va->largeur -1)
            all->vt->tab[i][a] = '*';
        else
            draw_tree(all, i, a);
    }
}

void draw_map(t_all *all)
{
    for (int i = 0; i != all->va->hauteur; i++){
        shorten_draw_map(all, i);
    }
    all->vt->tab[all->va->hauteur] = NULL;
}