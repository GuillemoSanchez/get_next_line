/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:22:58 by guisanch          #+#    #+#             */
/*   Updated: 2023/09/06 13:17:17 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	
#include "get_next_line.h"

char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	int		sz;

	sz = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n') && sz > 0)
	{
		sz = read(fd, buffer, BUFFER_SIZE);
		if (sz == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[sz] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*ft_new_stash(char *stash)
{
	int		index;
	int		y;
	char	*str;

	index = 0;
	while (stash[index] && stash[index] != '\n')
		index++;
	if (!stash[index])
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - index + 1));
	if (!str)
		return (NULL);
	index++;
	y = 0;
	while (stash[index])
	{
		str[y++] = stash[index++];
	}
	str[y] = '\0';
	free(stash);
	return (str);
}

char	*ft_get_line(char *stash)
{
	char	*str;
	int		index;

	if (!stash[index])
		return (NULL);
	while (stash[index] && stash[index] != '\n')
		index++;
	if (stash[index] == '\n')
		index++;
	str = malloc(sizeof(char) * (index + 1));
	index = 0;
	while (stash[index] && stash[index] != '\n')
		str[index] = stash[index++];
	if (stash[index] == '\n')
		str[index++] = '\n';
	str[index] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd1;

	fd1 = open("txt", O_RDONLY);

	while (1)
	{
		line = get_next_line(fd1);
		printf("line : %s", line);
		if (line == NULL)
		{
			break ;
		}
		free(line);
	}
	system("leaks -q a.out");
	return (0);
}
// int main()
// {
//     int fd, sz;
//     char* c = (char*)calloc(100, sizeof(char));
//     fd = open("foo.txt", O_RDONLY);
//     if (fd < 0) {
//         perror("r1");
//         exit(1);
//     }
//     sz = read(fd, c, 10);
//     printf("called read(% d, c, 10). returned that"
//            " %d bytes were read.\n",
//            fd, sz);
//     c[sz] = '\0';
//     printf("Those bytes are as follows: % s\n", c);
//     return 0;
// }