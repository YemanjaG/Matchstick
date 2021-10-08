/*
** EPITECH PROJECT, 2019
** Get_next_line
** File description:
** Get_next_line
*/

#include "include/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    if (!str)
        return 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

char* mr_clean(char* dirty)
{
    char *ret = malloc(sizeof(char) * my_strlen(dirty));
    int i = 0;
    int a = 0;
    for (i; dirty[i] != '\n'; i++);
    i++;
    for (i; dirty[i] != '\0'; i++){
        ret[a] = dirty[i];
        a++;
    }
    return ret;
}

char *add_to_str(char* ret, char* add, int i)
{
    char *str = malloc(sizeof(char) * my_strlen(ret) + i + 1);
    if (ret == NULL){
        my_strncpy(str, add, i);
    }
    else {
        my_strcpy(str, ret);
        my_strncat(str, add, i);
    }
    return str;
}

char *get_next_line(int fd)
{
    static int i = 0;
    static int len = -1;
    static char* buff;
    char* line = NULL;
    while (1){
        if (len <= i){
            i = 0;
            buff = malloc(sizeof(char) * READ_SIZE);
            len = read(fd, buff, READ_SIZE);
        } if (len == 0)
            return line;
        if (buff[i] == '\n' || buff[i] == '\0'){
            line = add_to_str(line, buff, i);
            buff = mr_clean(buff);
            len = my_strlen(buff);
            i = 0;
            return line;
        } if (i == len - 1)
            line = add_to_str(line, buff, i + 1);
        i++;
    }
}