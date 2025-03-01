/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:36:54 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:47 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	unsigned char			*u1;
	const unsigned char		*u2;

	u1 = (unsigned char *)s1;
	u2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (u1[i] - u2[i])
			return (u1[i] - u2[i]);
		if (u1 == NULL && u2 == NULL)
			return (0);
		i++;
	}
	return (0);
}
