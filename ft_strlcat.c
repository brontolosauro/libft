/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:59:05 by rfani             #+#    #+#             */
/*   Updated: 2024/12/20 23:07:53 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>
//#include <bsd/string.h>
//
//size_t	ft_strlcat(char *dst, const char *src, size_t size);
//
//int	main(void)
//{
////	char	*pqr_long = "pqrstuvwz";
////	char	*abc_short = "abcd";
////	char	*pqr_short = "pqrs";
////	char	*abc_long = "abcdefghi";
////	char	*dst = malloc(20 * sizeof(char));
////	char	*dst_o = malloc(20 * sizeof(char));
//	char	*dst = ft_calloc(15, sizeof(char));
//	char	*dst_o = ft_calloc(15, sizeof(char));
//	size_t	size = 15;
//	size_t	res;
////	char	*src = abc_short;
//	char	*src = "lorem ipsum dolor sit amet";
//
////	ft_memcpy(dst_o, pqr_long, ft_strlen(pqr_long));
//	memset(dst_o, 'r', 14);
//	printf("strlcat(\"%s\", \"%s\", %lu) = ", dst_o, src, size);
//	res = strlcat(dst_o, src, size);
//	printf("%lu\n", res);
//	printf("%s\n", dst_o);
////	ft_memcpy(dst, pqr_long, ft_strlen(pqr_long));
//	memset(dst, 'r', 14);
//	printf("ft_strlcat(\"%s\", \"%s\", %lu) = ", dst, src, size);
//	res = ft_strlcat(dst, src, size);
//	printf("%lu\n", res);
//	printf("%s\n", dst);
//
//	return (0);
//}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	if (!dst || !src)
		return (size);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len + 1)
		return (size + src_len);
	else if (size == dst_len + 1)
		return (dst_len + src_len);
	else if (size < src_len + dst_len + 1)
	{
		ft_memcpy(dst + dst_len, src, size - dst_len -1);
		*(dst + size - 1) = '\0';
	}
	else
		ft_memcpy(dst + dst_len, src, src_len + 1);
	return (dst_len + src_len);
}
