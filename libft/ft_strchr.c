/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:47:43 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:47 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	if (!s)
		return (NULL);
	uc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[50] = "dHOLA Pppp7";
	char	*result;

	result = ft_strchr(str, ' ');
	if (result != NULL)
		printf("1st coincidence or NULL value: '%c'\n", *result);
	else
		printf("No coincidence.\n");
	return (0);
}
*/