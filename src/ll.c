/*
** EPITECH PROJECT, 2020
** ll
** File description:
** ls -l file
*/

#include "struct.h"
#include <sys/stat.h>
#include <stdlib.h>
#include "ls.h"
#include "my.h"
#include <sys/types.h>
#include <pwd.h>
#include "grp.h"
#include <time.h>

void print_users(struct stat stats)
{
    struct passwd *user = getpwuid(stats.st_uid);
    struct group *group = getgrgid(stats.st_gid);

    my_putstr(" ");
    my_putstr(user->pw_name);
    my_putstr(" ");
    my_putstr(group->gr_name);
    my_putstr(" ");

}

void print_name(char *name)
{
    int i = 0;
    int place = 0;

    while (name[i] != '\0') {
        if (name[i] == '/')
            place = i;
        i++;
    }
    place++;
    if (name[place] == '.')
        return;
    while (name[place] != '\0') {
        my_putchar(name[place]);
        place++;
    }
}

void print_modification_time(struct stat stats)
{
    time_t *time = &(stats.st_mtime);
    char *time_str = ctime(time);
    int size = my_strlen(time_str);
    int i = 3;

    time_str[size - 9] = '\0';
    while (time_str[i] != '\0') {
        my_putchar(time_str[i]);
        i++;
    }
}

void print_total(files_t *files)
{
    struct stat stats;
    files_t *tmp = files;
    long int total = 0;

    while (tmp != NULL) {
        if (tmp->name[0] != '.') {
            stat(tmp->filepath, &stats);
            total += stats.st_blocks/ 2;
        }
        tmp = tmp->next;
    }
    my_putstr("total ");
    my_put_nbr(total);
    my_putchar('\n');
}

void ll(files_t *files)
{
    struct stat stats;
    files_t *tmp = files;

    print_total(tmp);
    while (tmp != NULL) {
        stat(tmp->filepath, &stats);
        if (tmp->name[0] != '.') {
            mode(stats.st_mode, stats);
            my_put_nbr(stats.st_nlink);
            print_users(stats);
            my_put_nbr(stats.st_size);
            print_modification_time(stats);
            my_putchar(' ');
            my_putstr(tmp->name);
            my_putstr("\n");
        }
        tmp = tmp->next;
    }
}