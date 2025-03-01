/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:06:01 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:47 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	source[50] = "12345ABCD?";
	char	dest[50];

	ft_memcpy(dest, source, 4);
	printf("parte copiada %s\n", dest);
	return (0);
}
*/