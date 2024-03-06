#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
/**
 * findFile - a function that get info
 * of the file
 * @filename: the name of the file
 */
void findFile(char *filename)
{
	struct stat st;
	unsigned int i;
	DIR *d;
	struct dirent *dir;
	char full_path[1000];

	d = opendir("/simple_shell/test/");
	if (filename == NULL)
		return;
	if (filename)
	{
		if (stat(filename, &st) == 0)
		{
			if ((st.st_mode & S_IFMT) == S_IFREG)
			{
				while ((dir = readdir(d)) != NULL)
				{
					if (dir->d_type == DT_DIR && \
						strcmp(dir->d_name, "..") != 0)
					{
						full_path[0] = '\0';
						strcat(full_path, dir->d_name);
						strcat(full_path, filename);
						printf("%s\n", full_path);
					}
				}
			}
			else
				printf("not regular file");
		}
	}
}
