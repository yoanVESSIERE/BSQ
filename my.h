/*
** EPITECH PROJECT, 2018
** BSQ.h
** File description:
** 
*/

#define LESS_OR_MORE_ARG 84
#define OPEN_ERROR       84

#ifndef VAR
#define VAR

typedef struct var
{
    int x1_tempo;
    int y1_tempo;
    int x2_tempo;
    int y2_tempo;
    int x1;
    int y1;
    int x2;
    int y2;
} var;

void my_putchar(char c);

int my_putstr(char const *str);

int my_getnbr(char const *str);

int my_put_nbr(int nb);

void take_val(char *buff, int *x_y_count, var *position, int i);

void disp(char *buff, var *position, int len, int nb_line);

void big(var *position);

void particular(char *buff, int nb_ligne, int len);

#endif