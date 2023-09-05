/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:22:55 by guisanch          #+#    #+#             */
/*   Updated: 2023/09/05 13:31:01 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *word, int chr)
{
	char	*res;
	int		cont;
	char	c;

	cont = 0;
	c = chr;
	while (word[cont] != '\0')
	{
		if (word[cont] == c)
		{
			res = (char *)&word[cont];
			return (res);
		}
		cont++;
	}
	if (chr != '\0')
		return (NULL);
	res = (char *)&word[cont];
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*string;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}

size_t	ft_strlen(char const *word)
{
	size_t		i;

	i = 0;
	while (word[i] != '\0')
	{
		i++;
	}
	return (i);
}
