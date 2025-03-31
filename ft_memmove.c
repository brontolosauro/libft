/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:52:48 by rfani             #+#    #+#             */
/*   Updated: 2024/12/21 12:51:46 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>
//
//void	*ft_memmove(void *dest, const void *src, size_t n);
static void	*move_bw(void *dest, const void *src, size_t n);
static void	*move_fw(void *dest, const void *src, size_t n);
//
//int	main(void)
//{
//	int		size = 128 * 1024 * 1024;
//	char	*dst = (char *)malloc(sizeof(char) * size);
//	char	*data = (char *)malloc(sizeof(char) * size);
//
//	ft_memset(data, 'A', size);
//	if (!dst)
//		printf("test failed\n");
//	ft_memmove(dst, data, size);
//	printf("tuttapposto\n");
//	return (0);
//}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!n)
		return (dest);
	if (!dest || !src)
		return (dest);
	if (dest == src)
		return (dest);
	if (src + n >= dest && dest > src)
		move_bw(dest, src, n);
	else if (dest + n > src && src > dest)
		move_fw(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

static void	*move_bw(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 1;
	while (i <= n)
	{
		*((unsigned char *)dest + n - i) = *((unsigned char *)src + n - i);
		i++;
	}
	return (dest);
}

static void	*move_fw(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
