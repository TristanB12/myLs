/*
** EPITECH PROJECT, 2020
** lrr
** File description:
** ls -rr tree
*/

#include "ls.h"
#include "struct.h"
#include "my.h"

char *cat_my_filepath(char *path, char *name)
{
    int size = my_strlen(path);

    if (path[size] != '/')
        path = my_strcat(path, "/");
    path = my_strcat(path, name);
    return path;
}

void lrr(char *filepath, char *flags, int i)
{
    DIR *dir_fd = opendir(filepath);
    struct stat stats;
    files_t *files = create_list_files(dir_fd, filepath);
    int j = i;
    char *tmp_fp = filepath;

    my_putstr(filepath);
    my_putstr(":\n");
    while (flags[i] != '\0') {
        files = select_flag(files, flags[i]);
        i++;
    }
    while (files != NULL) {
        stat(files->filepath, &stats);
        if (S_ISDIR(stats.st_mode) && files->name[0] != '.') {
            my_putstr("\n");
            tmp_fp = cat_my_filepath(filepath, files->name);
            lrr(tmp_fp, flags, j);
        }
        files = files->next;
    }
}