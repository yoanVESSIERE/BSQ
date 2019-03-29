/*
** EPITECH PROJECT, 2018
** BSQ.c
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

void loops(var *position, char *buff, int len)
{
    int loop = 1;

    while (loop) {
        position->x2_tempo++;
        position->y2_tempo++;
        for (int i = position->x1_tempo; i < position->x2_tempo; i++)
            for (int j = position->y1_tempo; j < position->y2_tempo; j++)
                if (buff[j * len + i - 1] != '.')
                    loop = 0;
    }
    position->x2_tempo--;
    position->y2_tempo--;
    big(position);
}

void algo(char *buff, int nb_ligne, int len)
{
    var position;
    int x_y_count[3] = {0, 0, 0};

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            x_y_count[1] += 1;
            x_y_count[0] = 0;
        }
        take_val(buff, x_y_count, &position, i);
        if (buff[i] == '.') {
            position.x1_tempo = x_y_count[0];
            position.y1_tempo = x_y_count[1];
            position.x2_tempo = x_y_count[0];
            position.y2_tempo = x_y_count[1];
            loops(&position, buff, len);
        }
        x_y_count[0]++;
    }
    disp(buff, &position, len, nb_ligne);
}

int calcul(char *buff)
{
    int i;
    char str[9];
    int nb_ligne;
    int len;

    for (i = 0; *buff != '\n'; i++) {
        str[i] = *buff;
        buff++;
    }
    buff++;
    for (len = 0; buff[len] != '\n'; len++);
    len++;
    nb_ligne = my_getnbr(str);
    //particular(buff, nb_ligne, len);
    algo(buff, nb_ligne, len);
    return (0);
}

int file_open(char *av[])
{
    int file;
    struct stat files;
    char *buff;
    int i = 0;

    stat(av[1], &files);
    buff = malloc(sizeof(char) * files.st_size);
    file = open(av[1], O_RDONLY);
    i = read(file, buff, files.st_size);
    i = i;
    buff[files.st_size] = '\0';
    close(file);
    calcul(buff);
    return (0);
}

int main(int ac, char *av[])
{
    int i = 0;

    if (ac != 2) {
        exit(LESS_OR_MORE_ARG);
    }
    if ((i = open(av[1], O_RDONLY)) == -1) {
        exit(OPEN_ERROR);
        close(i);
    }
    file_open(av);
    return (0);
}