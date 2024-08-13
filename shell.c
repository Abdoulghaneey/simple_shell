#include "main.h"

/**
 * main - Entry point for the shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *line;
    char **args;
    int status;

    do {
        prompt();
        line = read_line();
        if (line == NULL) {
            free(line);
            exit(0);
        }
        args = split_line(line);
        if (args[0] != NULL) {
            status = execute_command(args[0]);
        }
        free(line);
        free(args);
    } while (1);

    return (0);
}

/**
 * prompt - Prints the shell prompt
 */
void prompt(void)
{
    printf("#cisfun$ ");
}

/**
 * read_line - Reads a line from standard input
 *
 * Return: The input line
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1) {
        if (feof(stdin)) {
            free(line);
            return (NULL);  /* Handle EOF */
        } else {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    return (line);
}

/**
 * split_line - Splits a line into tokens (arguments)
 * @line: The input line
 *
 * Return: An array of tokens (arguments)
 */
char **split_line(char *line)
{
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return (tokens);
}

/**
 * execute_command - Executes a command
 * @command: The command to execute
 *
 * Return: The status of the command
 */
int execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execve(command, &command, NULL) == -1) {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Error forking */
        perror("hsh");
    } else {
        /* Parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (1);
}
