/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:22:48 by guisanch          #+#    #+#             */
/*   Updated: 2023/09/06 16:20:59 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_strchr(const char *word, char chr);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char const *word);
char	*get_next_line(int fd);
char	*read_to_stash(int fd, char *stash);
char	*ft_new_stash(char *stash);
char	*ft_get_line(char *stash);

#endif