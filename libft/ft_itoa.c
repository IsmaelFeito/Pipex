/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:34:55 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:47 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_len_num(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_len_num(n);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", 12);
	if (n == 0)
		str[0] = '0';
	if (n < 0 && n != -2147483648)
	{
		str[0] = '-';
		n *= -1;
	}
	str[i] = '\0';
	while (n != 0 && n != -2147483648)
	{
		i--;
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
/*
int main(void) 
{
    int numero = -12345;
    char *cadena = ft_itoa(numero);

    printf("El número como cadena de caracteres es: %s\n", cadena);
    freedom((void **)&cadena);
    return 0;
}
*/
