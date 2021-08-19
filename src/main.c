/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ls.h"
#include "struct.h"
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include <errno.h>

int get_nbsize(int nb)
{
    int count = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb = nb / 10;
        count++;
    }
    return count;
}

int get_maxsize(files_t *files)
{
    files_t *tmp = files;
    struct stat stats;
    int maxsize = 0;
    int size = 0;
    int tmp_nb = 0;

    while (tmp != NULL) {
        stat(tmp->name, &stats);
        tmp_nb = stats.st_size;
        size = get_nbsize(tmp_nb);
        if (maxsize < size)
            maxsize = size;
        tmp = tmp->next;
    }
    return maxsize;
}

files_t *select_flag(files_t *files, char flag)
{
    if (flag == 's')
        ls(files);
    if (flag == 'l')
        ll(files);
    if (flag == 'r')
        files = lr(files);
    else if (flag == 't')
        files = lt(files);
    return files;
}

void manage_flags(int ac, char *flags, DIR *dir_fd, char *filepath)
{
    files_t *files = create_list_files(dir_fd, filepath);
    int i = 0;

    if (ac == 1)
        ls(files);
    else {
        while (flags[i] != '\0') {
            if (flags[i] == 'R') {
                i++;
                lrr(filepath, flags, i);
                return;
            }
            files = select_flag(files, flags[i]);
            i++;
        }
    }
}

int main(int ac, char **av)
{
    DIR *dir_fd;
    char *filepath = get_filepath(ac, av);
    char *flags = get_flags(ac, av);

    dir_fd = opendir(filepath);
    if (dir_fd == NULL) {
        my_put_nbr(errno);
        return (84);
    }
    manage_flags(ac, flags, dir_fd, filepath);
    return 0;
}