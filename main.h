#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int execute_command(char *command);
void prompt(void);
char *read_line(void);
char **split_line(char *line);

#endif /* MAIN_H */
