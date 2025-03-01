/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:30:51 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:47 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s2;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = start;
	j = 0;
	while (s[i])
		i++;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = start;
	while (s[i] && j < len)
	{
		s2[j++] = s[i++];
	}
	s2[j] = '\0';
	return (s2);
}
