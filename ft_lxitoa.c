/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lxitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:56:38 by rfani             #+#    #+#             */
/*   Updated: 2025/03/17 11:53:14 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_lxitoa(unsigned long int n);
static int	ft_n_lhex_digit(unsigned long int n);
static void	fill_itoa(char *itoa, unsigned long int n);

char	*ft_lxitoa(unsigned long int n)
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
		itoa = ft_calloc(ft_n_lhex_digit(n) + 1, sizeof(char));
		if (!itoa)
			return (NULL);
	}
	fill_itoa(itoa, n);
	return (itoa);
}

static int	ft_n_lhex_digit(unsigned long int n)
{
	int	n_digit;

	n_digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		n_digit++;
	}
	return (n_digit);
}

static void	fill_itoa(char *itoa, unsigned long int n)
{
	int	n_digit;
	int	rmd;

	n_digit = ft_n_lhex_digit(n);
	while (n != 0)
	{
		rmd = n % 16;
		if (rmd < 10)
			itoa[n_digit - 1] = '0' + rmd;
		else
			itoa[n_digit - 1] = 'a' + rmd - 10;
		n /= 16;
		n_digit--;
	}
}
