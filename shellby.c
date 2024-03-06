#include "main.h"
/**
 * main - main function
 * @argc: integer numb of argument
 * @argv: list of argument
 * @envp: environment variable
 * Return: success or failure
 */
int main(int __attribute__ ((unused)) argc, char __attribute__ ((unused)) *argv[], char *envp[])
{
	shell_loop(envp);
	return (EXIT_SUCCESS);
}
