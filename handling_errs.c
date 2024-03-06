#include "shell.h"

/**
 * print_error - showing err
 * @us_input: user_input
 * @c: Counter
 * @argv: Args prior to prog initiation(argv[0] == prog_name of shell)
 */

void print_error(char *us_input, int c, char **argv)
{
	char *err;

	PRINT(argv[0]);
	PRINT(": ");
	err = _itoa(c);
	PRINT(err);
	free(err);
	PRINT(": ");
	PRINT(us_input);
	PRINT(": not found\n");
}

/**
 * cust_err - showing user defined err
 * @argv: Args prior to prog initiation(argv[0] == Prog_name of shell)
 * @c: counter of err
 * @cmd: cmd_strs arr
 */

void cust_err(char **argv, int c, char **cmd)
{
	char *err = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(err);
}

/**
 * file_err - showing user def error
 * @argv: Args prior to prog initiation(argv[0] == Prog_name of shell)
 * @c: Error Count
 */

void file_err(char **argv, int c)
{
	char *err = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(err);
}

