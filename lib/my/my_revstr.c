/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    int count = 0;
    int i = 0;
    int temp = 0;

    while (str[count] != '\0') {
        count++;
    }
    count = count - 1;
    while (i < count) {
        temp = str[count];
        str[count] = str[i];
        str[i] = temp;
        i++;
        count--;
    }
    return (str);
}
