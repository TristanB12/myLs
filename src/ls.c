/*
** EPITECH PROJECT, 2020
** ls
** File description:
** ls
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ls.h"
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "struct.h"
#include <errno.h>

files_t *create_list(files_t *list, char *str, int type, char *name)
{
    files_t *element;
    files_t *tmp = list;

    while (tmp != NULL && tmp->next != NULL) {
        tmp = tmp->next;
    }
    element = malloc(sizeof(files_t));
    element->name = name;
    element->type = type;
    element->filepath = str;
    element->next = NULL;
    if (tmp)
        tmp->next = element;
    else
        list = element;

    return list;
}

files_t *create_list_files(DIR *dir_fd, char *filepath)
{
    struct dirent *dir_stat = readdir(dir_fd);
    files_t *list = NULL;
    struct stat stats;
    char *name = ".";
    int type = 0;

    while (dir_stat != NULL) {
        stat(dir_stat->d_name, &stats);
        if (S_ISDIR(stats.st_mode)) {
            type = 1;
        }
        if (filepath[0] == '.' && my_strlen(filepath) == 1)
            name = dir_stat->d_name;
        else
            name = cat_my_filepath(filepath, dir_stat->d_name);
        list = create_list(list, name, type, dir_stat->d_name);
        dir_stat = readdir(dir_fd);
    }
    return list;
}

void ls(files_t *files)
{
    files_t *tmp = files;

    while (tmp->next != NULL) {
        if (tmp->name[0] != '.') {
            my_putstr(tmp->name);
            my_putstr("\n");
        }
        tmp = tmp->next;
    }
    if (tmp->name[0] != '.') {
        my_putstr(tmp->name);
        my_putstr("\n");
    }
}