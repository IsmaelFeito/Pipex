/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:09:30 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:47 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_d;
	const unsigned char	*tmp_s;

	if (!dst && !src)
		return (NULL);
	tmp_d = (unsigned char *)dst;
	tmp_s = (const unsigned char *)src;
	if (tmp_d == tmp_s)
		return (dst);
	if (tmp_d < tmp_s || tmp_d >= (tmp_s + len))
	{
		while (len--)
			*tmp_d++ = *tmp_s++;
	}
	else
	{
		tmp_d += len;
		tmp_s += len;
		while (len--)
			*--tmp_d = *--tmp_s;
	}
	return (dst);
}
/*
int	main(void)
{
	char	source[50] = "12345";
	char	dest[50] = "ABCDE";

	ft_memmove(dest, source, 3);
	printf("resultado final: %s", dest);
	return (0);
}
*/