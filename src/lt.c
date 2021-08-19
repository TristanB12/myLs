/*
** EPITECH PROJECT, 2020
** lt
** File description:
** flag -t: sorting by date of modification
*/

#include "ls.h"
#include <stdlib.h>
#include "struct.h"
#include <stddef.h>
#include "my.h"
#include <stdio.h>

int check_sort(files_t *l_a)
{
    files_t *tmp = l_a;

    while (tmp->next != NULL) {
        if (tmp->time > tmp->next->time)
            return 84;
        tmp = tmp->next;
    }
    return 0;
}

void re_init(files_t **l_a, files_t **l_b)
{
    while (l_b[0] != NULL) {
        pa(&l_a[0], &l_b[0]);
    }
    return ;
}

void swap_or_put(files_t **l_a, files_t **l_b)
{
    if (l_a[0]->next == NULL)
    pb(&l_a[0], &l_b[0]);
    else if (l_a[0]->time <= l_a[0]->next->time)
    pb(&l_a[0], &l_b[0]);
    else
        l_a[0] = sa(l_a[0]);
    return ;
}

files_t *put_time(files_t *files)
{
    files_t *tmp = files;
    struct stat stats;

    while (tmp != NULL) {
        stat(tmp->name, &stats);
        tmp->time = stats.st_mtime;
        tmp = tmp->next;
    }
    return files;
}

files_t *lt(files_t *l_a)
{
    l_a = put_time(l_a);
    files_t *l_b = NULL;

    while (check_sort(l_a) == 84) {
        while (l_a != NULL) {
            swap_or_put(&l_a, &l_b);
        }
        re_init(&l_a, &l_b);
    }
    l_a = lr(l_a);
    return l_a;
}
