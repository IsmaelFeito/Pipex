/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:46:22 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/02/24 19:04:48 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_argc(char const *s, char c)
{
	int	i;
	int	argcount;

	i = 0;
	argcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			argcount++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (argcount);
}

static void	ft_clean_mem(char **result, int i)
{
	while (i >= 0)
		freedom((void **)&result[i--]);
	freedom((void **)&result);
}

static char	**ft_indiv_words(char **result, char const *s, char c, int i)
{
	int	total_len;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				total_len = ft_strlen(s);
			else
				total_len = ft_strchr(s, c) - s;
			result[i] = ft_substr(s, 0, total_len);
			if (result[i] == NULL)
			{
				ft_clean_mem(result, i - 1);
				return (NULL);
			}
			s += total_len;
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		argc;
	char	**result;

	i = 0;
	argc = ft_count_argc(s, c);
	result = (char **)malloc((argc + 1) * (sizeof (char *)));
	if (result == NULL)
		return (NULL);
	if (!s || !result)
		return (NULL);
	result = ft_indiv_words(result, s, c, i);
	if (!result)
		return (NULL);
	return (result);
}
