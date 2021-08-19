/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** return the diff
*/

#include <stdlib.h>
#include <string.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i = i+1;
    }
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int diff;
    int size = my_strlen(s1);

    while (i < size && s1[i] == s2[i]) {
        i++;
    }
    diff = s1[i] - s2[i];
    return (diff);
}
