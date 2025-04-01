/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:07:11 by rfani             #+#    #+#             */
/*   Updated: 2025/03/17 11:58:04 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_uitoa(unsigned int n);
static int	ft_n_digit(unsigned int n);
static void	fill_itoa(char *itoa, unsigned int n);

char	*ft_uitoa(unsigned int n)
{
	char	*itoa;

	if (n == 0)
	{
		itoa = ft_calloc(2, sizeof(char));
		if (!itoa)
			return (NULL);
		itoa[0] = '0';
		return (itoa);
	}
	else
	{
		itoa = ft_calloc(ft_n_digit(n) + 1, sizeof(char));
		if (!itoa)
			return (NULL);
	}
	fill_itoa(itoa, n);
	return (itoa);
}

static int	ft_n_digit(unsigned int n)
{
	int	n_digit;

	n_digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		n_digit++;
	}
	return (n_digit);
}

static void	fill_itoa(char *itoa, unsigned int n)
{
	int	n_digit;

	n_digit = ft_n_digit(n);
	while (n != 0)
	{
		itoa[n_digit - 1] = '0' + n % 10;
		n /= 10;
		n_digit--;
	}
}
