#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
/**
 * main - main function
 * @void:
 * Return 0
 */
int main(void)
{
	pid_t my_pid;
	pid_t my_ppid;

	my_pid = getpid();
	my_ppid = getppid();
	printf("this is the pid %u\n", my_pid);
	printf("this is the parent pid %u\n", my_ppid);
	return (0);
}


