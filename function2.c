/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** 
*/
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int my_put_nbr(int nb)
{
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    if (nb < 0 && (nb * -1) > 9) {
        my_putchar(45);
        nb = nb * -1;
        my_put_nbr(nb / 10);
    }
    else if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    my_putchar(nb % 10 + '0');
    return (0);
}

void take_val(char *buff, int *x_y_count, var *position, int i)
{
    if (x_y_count[2] == 0 && buff[i] == '.') {
            x_y_count[2]++;
            position->x1 = x_y_count[0];
            position->y1 = x_y_count[1];
            position->x2 = x_y_count[0];
            position->y2 = x_y_count[1];
        }
}

void disp(char *buff, var *position, int len, int nb_line)
{
    int i = 0;

    for (int i = position->x1; i < position->x2; i++)
        for (int j = position->y1; j < position->y2; j++)
            buff[j * len + i - 1] = 'x';
    i = write(1, buff, nb_line * len);
    i = i;
}

void big(var *position)
{
    if (position->x2_tempo - position->x1_tempo > position->x2 - position->x1) {
        position->x2 = position->x2_tempo;
        position->x1 = position->x1_tempo;
        position->y2 = position->y2_tempo;
        position->y1 = position->y1_tempo;
    }
}