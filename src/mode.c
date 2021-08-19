/*
** EPITECH PROJECT, 2020
** mode
** File description:
** type and rwx of file
*/

#include "my.h"
#include "ls.h"
#include <sys/stat.h>

void good_rwx(char c)
{
    if (c == '0')
        my_putstr("---");
    else if (c == '1')
        my_putstr("--x");
    if (c == '2')
        my_putstr("-w-");
    else if (c == '3')
        my_putstr("-wx");
    if (c == '4')
        my_putstr("r--");
    else if (c == '5')
        my_putstr("r-x");
    if (c == '6')
        my_putstr("rw-");
    else if (c == '7')
        my_putstr("rwx");
}

void print_rwx(char *octal)
{
    int size = my_strlen(octal);

    size = size - 3;
    while (octal[size] != '\0') {
        good_rwx(octal[size]);
        size++;
    }
}

void print_type(struct stat stats)
{
    if (S_ISDIR(stats.st_mode))
        my_putstr("d");
    else if (S_ISLNK(stats.st_mode))
        my_putstr("f");
    else {
        my_putstr("-");
    }
}

void mode(int mode, struct stat stats)
{
    char *octal = convert_octal(mode);
    int size = my_strlen(octal);
    if (mode > 30000 && octal[size - 1] == '0')
        octal[size - 1] = '\0';
    print_type(stats);
    print_rwx(octal);
    my_putstr(" ");
}