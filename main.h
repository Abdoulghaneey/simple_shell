#ifndef shell
#define shell
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPipe_redir(char **args);
int execute(int argc, char **argv, char **envp);
bool isWildcard(char **args);
void errormessage(char *s);
void shell_loop(char **envp);
int shell_execute(char **tokens, char **envp);
typedef struct ops
{
	char *op;
	int (*func)(char **ap);
} op_t;
char *_getline(void);
char **_strtok(char *line);
void findFile(char *filename);
int (*get_op_func(const char *s))(char **);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
#endif
