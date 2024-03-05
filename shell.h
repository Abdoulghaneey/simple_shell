#ifndef SHELL_H
#define SHELL_H
<<<<<<< HEAD
#include "symtab/symtab.h"
#include "source.h"

void print_prompt1(void);
void print_prompt2(void);

char *read_cmd(void);

int  parse_and_execute(struct source_s *src);

void initsh(void);

/* shell builtin utilities */
int dump(int argc, char **argv);

/**
 * builtin_s - built in utilities
 * @name: utility name
 * @func: function to call to execute the utility
 *
 * Description: struct for builtin utilities
 */
struct builtin_s
{
	char *name;
	int (*func)(int argc, char **argv);
};

/* the list of builtin utilities */
extern struct builtin_s builtins[];

/* and their count */
extern int builtins_count;

struct word_s
{
    char  *data;
    int    len;
    struct word_s *next;
};

struct word_s *make_word(char *str);
void free_all_words(struct word_s *first);

char *wordlist_to_str(struct word_s *word);
void delete_char_at(char *str, size_t index);
int is_name(char *str);
size_t find_closing_quote(char *data);
size_t find_closing_brace(char *data);
char *substitute_str(char *s1, char *s2, size_t start, size_t end);
int substitute_word(char **pstart, char **p, size_t len, char *(func)(char *), int add_quotes);


char   *strchr_any(char *string, char *chars);
char   *quote_val(char *val, int add_quotes);
int     check_buffer_bounds(int *count, int *len, char ***buf);
void    free_buffer(int len, char **buf);

char *tilde_expand(char *s);
char *var_expand(char *orig_var_name);
char *command_substitute(char *orig_cmd);
char *arithm_expand(char *expr);
struct word_s *field_split(char *str);
struct word_s *pathnames_expand(struct word_s *words);
void remove_quotes(struct word_s *wordlist);
struct word_s *word_expand(char *orig_word);
#endif
=======

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


/*constants*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct map - a struct that maps a command name to a function 
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/*helpers*/
void print(char *, int);
char **tokenizer(char *, char *);
void remove_newline(char *);
int _strlen(char *);
void _strcpy(char *, char *);

/*helpers2*/
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/*helpers3*/
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int);
void remove_comment(char *);

/*utils*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

/*built_in*/
void env(char **);
void quit(char **);

/*main*/
extern void non_interactive(void);
extern void initializer(char **current_command, int type_command);

#endif /*SHELL_H*/


>>>>>>> 313cda82294dda63bc4c980def924c34798fa0ca
