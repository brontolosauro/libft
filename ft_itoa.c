/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:30:24 by rfani             #+#    #+#             */
/*   Updated: 2024/12/21 12:58:57 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>
//
//char	*ft_itoa(int n);
static int	ft_n_digit(int n);
static void	fill_itoa(char *itoa, int n);
//
//int	main(void)
//{
//	printf("ft_itoa(1000034) = %s\n", ft_itoa(1000034));
//	printf("ft_itoa(-10004) = %s\n", ft_itoa(-10004));
//	printf("ft_itoa(2147483647) = %s\n", ft_itoa(2147483647));
//	printf("ft_itoa(-2147483648) = %s\n", ft_itoa(-2147483648));
//	return (0);
//}

char	*ft_itoa(int n)
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
	else if (n < 0)
	{
		itoa = ft_calloc(ft_n_digit(n) + 2, sizeof(char));
		if (!itoa)
			return (NULL);
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

static int	ft_n_digit(int n)
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

static void	fill_itoa(char *itoa, int n)
{
	int	n_digit;

	n_digit = ft_n_digit(n);
	if (n < 0)
	{
		itoa[0] = '-';
		itoa[n_digit] = '0' + -1 * (n % 10);
		n = -1 * (n / 10);
		n_digit--;
		while (n != 0)
		{
			itoa[n_digit] = '0' + n % 10;
			n /= 10;
			n_digit--;
		}
	}
	else
	{
		while (n != 0)
		{
			itoa[n_digit - 1] = '0' + n % 10;
			n /= 10;
			n_digit--;
		}
	}
}
