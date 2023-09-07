/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:18:25 by guisanch          #+#    #+#             */
/*   Updated: 2023/09/07 12:36:20 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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