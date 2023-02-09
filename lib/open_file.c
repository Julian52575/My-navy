/*
** EPITECH PROJECT, 2022
** Open file
** File description:
** open a file and returns its content as a char * or NULL in case of error
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int my_ascii_test(char c);

//max ~30  / 31 avec \n
char *open_file(char *file_path)
{
    int fd = 0;
    char *txt = malloc(sizeof(char) * 33);
    char buffer[2];
    int b = 0;
    if ( (fd = open(file_path, O_RDONLY)) == -1)
        return NULL;
    for (; read(fd, buffer, 1) > 0 && b < 32; b++) {
        txt[b] = buffer[0];
    }
    if (b == 33) {
        free(txt);
        return NULL;
    }
    txt[b] = '\0';
    return txt;
}
