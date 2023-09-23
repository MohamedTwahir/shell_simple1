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
#include <sys/type.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

char *comment_deleter(char *ingiza);
void loop(info_shell *infosh);

char *line_reader(int reader);


#endif
