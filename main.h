#ifndef MAIN_H
#define MAIN_H

/***** Used Macros *****/
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

/*** std libraries ***/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/******** FUNCTIONS THAT ARE STRING RELATED **********/

char *_strncpy(char *destin, char *sorce, int count_n)
int _strlen(char *strng)
int _putchar(char ch)
int _atoi(char *strng)
void _puts(char *strng)
int _strcmp(char *strng1, char *strng2)
int _isalpha(int ch)

char *_strcpy(char *destin, char *sorce)
char *_strcat(char *destin, char *sorce)

int _strncmp(const char *strng1, const char *strng2, size_t c)
char *_strchr(char *strng, char ch)
char *_strdup(char *strng)

/* Prototype of funcs that handle mem */

void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new)
void free_all(char **cmd, char *line)
char *_memcpy(char *destin, char *sorce, unsigned int n)
void *fill_an_array(void *a, int el, unsigned int len)
void *_calloc(unsigned int size)

/* Prototypes for Input functions and other related ones */

unsigned int check_delim(char ch, const char *strng)
int history(char *user_input)
char *_strtok(char *strng, const char *delim)
char **parse_cmd(char *user_input)
void cmd_prompt(void)
char *_getline()
char **separator(char *user_input)
char *enter(char *strng)
char *space(char *strng)
void hashtag_treated(char *bufer)

/***** Functions that handle file args ******/

void read_the_doc(char *doc, char **argv)
void handle_doc(char *line, int cnt, FILE *file_pointre, char **argv)
void exit_doc_cond(char **cmd, char *line, FILE *file_pointre)


void signal_to_be_treated(int treated_sig)
int cmd_chk(char **cmd, char *user_input, int tc, char **argv)

/* Prototypes of functions that handles errors */

void print_error(char *user_input, int c, char **argv)
void _prerror(char **argv, int c, char **cmd)
void error_file(char **argv, int c)

/* The function for Builtin cmd handlers and exec */

int check_builtin(char **cmd)
int handle_builtin(char **cmd, int cond)
void exit_file_bool(char **cmd, char *user_input, char **argv, int c, int cond_exit)

int change_dir(char **cmd, __attribute__((unused)) int cond)
int disp_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int cond)
int echo_bool(char **cmd, int cond)
int disp_hist(__attribute__((unused)) char **c, __attribute__((unused)) int cond)

/* environmental variable */

void free_env(char **env)
void create_env(char **env)
extern char **env_def;

/* Prototype of functions that handle help */

void cd_help(void)
void help_help(void)
void all_help(void)
void alias_help(void)
void exit_help(void)
void env_help(void)
void unsetenv_help(void)
int show_help(char **cmd, __attribute__((unused)) int cond)
void setenv_help(void)

/* Prototypes for finding path */

int path_cmd(char **cmd)
char *build(char *tok, char *val)
char *_getenv(char *env_name)

/* Protypes for printing nums */

void print_number(unsigned int num)
void print_number_int(int num)
int print_echo(char **cmd)

/* Struct for inbuilt cmds */

/**
 * struct _inbuilt - This Defines a struct that contains built-in cmds and their implementation
 * @cmd: - Built-in cmd
 * @func: - aiming at created funcs that has same func as built in cmds
 */
typedef struct _inbuilt
{
char *cmd;
int (*func)(char **line, int cond);
} inbuilt;

#endif

