/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:28:24 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:47 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needdle, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*result;

	i = 0;
	result = NULL;
	if (needdle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (needdle[j] != '\0'
			&& haystack[i + j] == needdle[j] && (i + j) < len)
		{
			if (j == 0)
				result = &haystack[i];
			j++;
		}
		if (needdle[j] == '\0')
			return ((char *)result);
		++i;
	}
	return (NULL);
}
