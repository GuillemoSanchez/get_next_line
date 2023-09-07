/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:25:45 by guisanch          #+#    #+#             */
/*   Updated: 2023/09/07 12:25:55 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *word, char chr)
{
	char	*res;
	int		cont;

	cont = 0;
	if (!word)
		return (0);
	while (word[cont] != '\0')
	{
		if (word[cont] == chr)
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
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
