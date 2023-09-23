#ifndef _SHELL_H_
#define _SHELL_H_

/*
 * File: shell header file
 * Author: Mohamed Twahir
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZER 1024
#define DELIMIZER " \t\r\n\a"

char *comment_deleter(char *ingiza);
void loop(info_shell *infosh);

char *line_reader(int reader);
char **line_divider(char *input);

int is_executable(info_shell *infosh);
int check_error(char *dir. info_shell *infosh);
int execmd(info_shell *infosh);


#endif
