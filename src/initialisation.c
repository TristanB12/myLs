/*
** EPITECH PROJECT, 2020
** initialisation
** File description:
** init all we need to start ls
*/

#include <stdlib.h>
#include "my.h"

char *put_s(char *flags, int count_l, int a)
{
    if (count_l == 0) {
        flags[a] = 's';
        a++;
    }
    flags[a] = '\0';
    return flags;
}

char *get_flags(int ac, char **av)
{
    char *flags = malloc(sizeof(char) * ac + 1);
    int i = 0, a = 0, count_l = 0;
    int j = 1;
    char *flags_pred = "Rtrl";

    while (i < 4) {
        j = 1;
        while (av[j] != NULL) {
            if (av[j][1] == flags_pred[i] && av[j][0] == '-') {
                flags[a] = flags_pred[i];
                a++;
            if (flags[a - 1] == 'l')
                count_l++;
            }
            j++;
        }
        i++;
    }
    flags = put_s(flags, count_l, a);
    return flags;
}

char *get_filepath(int ac, char **av)
{
    char *fp = av[ac - 1];

    if (ac == 1)
        return ".";
    if (my_strcmp(fp, "-l") != 0 && my_strcmp(fp, "-R") != 0 &&
        my_strcmp(fp, "-d") != 0 && my_strcmp(fp, "-r") != 0 &&
        my_strcmp(fp, "-t") != 0) {
        return fp;
        }
    return ".";
}