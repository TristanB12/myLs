/*
** EPITECH PROJECT, 2020
** functions
** File description:
** function for ls -t: sorting by modif time
*/

#include "struct.h"

void pa(files_t **l_a, files_t **l_b)
{
    files_t *one = l_a[0];
    files_t *two = l_b[0];
    files_t *three = l_b[0]->next;

    two->next = one;
    l_b[0] = three;
    l_a[0] = two;
}

void pb(files_t **l_a, files_t **l_b)
{
    files_t *one = l_b[0];
    files_t *two = l_a[0];
    files_t *three = l_a[0]->next;

    two->next = one;
    l_a[0] = three;
    l_b[0] = two;
}

files_t *sa(files_t *l_a)
{
    files_t *one = l_a;
    files_t *two = l_a->next;
    files_t *three = l_a->next->next;

    two->next = one;
    one ->next = three;
    l_a = two;
    return l_a;
}
