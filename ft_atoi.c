/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:57:29 by rfani             #+#    #+#             */
/*   Updated: 2024/12/21 12:52:22 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
//
// int	ft_atoi(const char *str);
static int	pramble(const char *str, int *i, int *sign);
static int	ft_isspace(char c);
static int	issign(const char *str, int *i, int *sign);
//
// int main()
// {
// 	char str[] = "";
// 	printf("str[]=\"%s\"\n", str);
// 	int amount = ft_atoi(str);
// 	printf("ft_atoi(str) = %d\n", amount);
//     amount = atoi(str);
//     printf("atoi(str) = %d\n", amount);
//
// 	return (0);
// }

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	if (!str)
		return (0);
	if (!pramble(str, &i, &sign))
		return (0);
	while (ft_isdigit(str[i]) && str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

static int	pramble(const char *str, int *i, int *sign)
{
	while (ft_isspace(str[*i]) && str[*i])
		*i += 1;
	if (issign(str, i, sign) && str[*i])
		*i += 1;
	if (ft_isdigit(str[*i]) && str[*i])
		return (1);
	else
		return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	issign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		return (1);
	}
	else if (str[*i] == '+')
	{
		*sign = 1;
		return (1);
	}
	return (0);
}
