/*
** EPITECH PROJECT, 2020
** ls
** File description:
** ls header
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "struct.h"

#ifndef LS_H_
#define LS_H_

files_t *sa(files_t *l_a);
void pb(files_t **l_a, files_t **l_b);
void pa(files_t **l_a, files_t **l_b);
void display(files_t *files);
void mode(int mode, struct stat stats);
char *convert_octal(int nb);
void ls(files_t *files);
files_t *create_list_files(DIR *dir_fd, char *filepath);
char *get_filepath(int ac, char **av);
char *get_flags(int ac, char **av);
void ll(files_t *files);
files_t *select_flag(files_t *files, char flag);
int get_nbsize(int nb);
files_t *lt(files_t *files);
files_t *lr(files_t *files);
void lrr(char *filepath, char *flags, int i);
char *cat_my_filepath(char *path, char *name);

#endif /* !LS_H_ */
