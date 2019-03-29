/*
** EPITECH PROJECT, 2018
** function3.c
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

void particular(char *buff, int nb_ligne, int len)
{
    if (nb_ligne == 1 && buff[0] != 'o') {
        buff[0] = 'x';
        my_putstr(buff);
        exit(0);
    }
    if (len == 1 && buff[0] != 'o') {
        buff[0] = 'x';
        my_putstr(buff);
        exit(0);
    }
}