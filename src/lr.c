/*
** EPITECH PROJECT, 2020
** lr
** File description:
** ls -r: reverse order to print
*/

#include "ls.h"
#include "struct.h"
#include "my.h"

void rev(files_t **l_a, files_t **l_b)
{
    files_t *one = l_b[0];
    files_t *two = l_a[0];
    files_t *three = l_a[0]->next;

    two->next = one;
    l_a[0] = three;
    l_b[0] = two;
}

files_t *lr(files_t *files)
{
    files_t *reversed_files = NULL;
    files_t *tmp = files;

    while (tmp != NULL) {
        rev(&tmp, &reversed_files);
    }
    return reversed_files;
}