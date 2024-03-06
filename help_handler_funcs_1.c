#include "shell.h"
/**
 * all_help - Shows all available builtin help via commands
 */
void all_help(void)
{
	char *info = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * help_alias - show help msg via the  builtin command 'alias'
 */
void help_alias(void)
{
	char *info = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, info, _strlen(info));
	info  = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * cd_help - show help msg via the  builtin command 'cd'
 */
void cd_help(void)
{
	char *info = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, info, _strlen(info));
	info = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "after a change of directory.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * help_exit - show help msg via the  builtin command 'exit'
 */
void help_exit(void)
{
	char *info = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " exit 0.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}

/**
 * help_help - show help msg via the  builtin command 'help'
 */
void help_help(void)
{
	char *info = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "builtin command.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}
