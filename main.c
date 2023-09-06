#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
void leaks()
{
	system("leaks -q a.out");
}

int main(){
	int fd;
	char *line;

	fd = open("largo.txt", O_RDONLY);
	//atexit(leaks);
	line = get_next_line(fd);
	while(line)
	{
		printf("----->%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
		
	return (0);
}