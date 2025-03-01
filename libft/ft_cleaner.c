/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 14:47:28 by ifeito-m          #+#    #+#             */
/*   Updated: 2025-02-27 14:47:28 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_cleaner_aux(char *str, char remover)
{
	char	*tmp;
	int		i;
	int		j;

	if (!str || !*str)
		return (NULL);
	tmp = (char *)malloc(ft_strlen(str) + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != remover)
			tmp[j++] = str[i];
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_cleaner(char *str, char *removers)
{
	int	i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (removers[i] != '\0')
	{
		str = ft_cleaner_aux(str, removers[i]);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}
