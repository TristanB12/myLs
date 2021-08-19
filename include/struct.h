/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_files
{
    char *name;
    long int time;
    char *colour;
    char *filepath;
    int type;
    struct s_files *next;
}files_t;

#endif /* !STRUCT_H_ */
