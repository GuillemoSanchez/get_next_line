/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:22:58 by guisanch          #+#    #+#             */
/*   Updated: 2023/09/05 15:55:32 by guisanch         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
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