/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:16:50 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:47 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t			len_s1;
	const char		*first;
	const char		*last;
	char			*total;

	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	first = s1;
	last = s1 + len_s1 - 1;
	while (first <= last && is_in_set(*first, set))
		first++;
	while (last >= first && is_in_set(*last, set))
		last--;
	total = ft_substr(first, 0, last - first + 1);
	return (total);
}
/*
int main(void) 
{
    const char *s1 = "Hello World!";
    const char *set = "Helorld!";
    char *trimmed = ft_strtrim(s1, set);
    if (trimmed) {
        printf("Cadena original: \"%s\"\n", s1);
        printf("Cadena después de eliminar: \"%s\"\n", trimmed);
        freedom((void **)&trimmed); // Libera la memoria asignada por ft_strtrim
    } else {
        printf("Error: No se pudo realizar la operación.\n");
    }
    return 0;
}
*/