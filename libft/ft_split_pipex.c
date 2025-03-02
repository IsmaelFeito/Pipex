/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 14:42:52 by ifeito-m          #+#    #+#             */
/*   Updated: 2025-02-27 14:42:52 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	asign_memory(char const *s, char c, int i, int k)
{
	char	q;

	q = '\0';
	while (s[i] != '\0')
	{
		while (s[i] == c && q == '\0')
			i++;
		if (s[i] != '\0')
		{
			k++;
			while ((s[i] != c || q != '\0') && s[i] != '\0')
			{
				if ((s[i] == '\'' || s[i] == '"') && (q == '\0' || q == s[i]))
				{
					if (q == '\0')
						q = s[i];
					else
						q = '\0';
				}
				i++;
			}
		}
	}
	return (k);
}

static void	*free_memory(char **str, int k)
{
	while (k > 0)
	{
		free(str[k]);
		k--;
	}
	free(str);
	return (NULL);
}

static int	asign_j(const char *s, char c, int i)
{
	int		j;
	char	q;

	j = i;
	q = '\0';
	while ((s[j] != c || q != '\0') && s[j] != '\0')
	{
		if ((s[j] == '\'' || s[j] == '"') && (q == '\0' || q == s[j]))
		{
			if (q == '\0')
				q = s[j];
			else
				q = '\0';
		}
		j++;
	}
	return (j);
}

static char	**true_split(char **str, char const *s, char c, int i)
{
	int	k;
	int	j;
	int	l;

	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && (i == 0 || (s[i - 1] != '\'' && s[i - 1] != '"')))
			i++;
		if (s[i] != '\0')
		{
			j = asign_j(s, c, i);
			str[k] = (char *)malloc((j - i + 1) * sizeof(char));
			if (!str[k])
				return (free_memory(str, k));
			l = 0;
			while (i < j)
				str[k][l++] = s[i++];
			str[k++][l] = '\0';
		}
	}
	str[k] = NULL;
	return (str);
}

char	**ft_split_pipex(char const *s, char c)
{
	int		i;
	int		k;
	char	**str;

	i = 0;
	k = 0;
	k = asign_memory(s, c, i, k);
	str = (char **)malloc((k + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = true_split(str, s, c, i);
	return (str);
}
