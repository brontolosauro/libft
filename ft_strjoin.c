/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:52:32 by rfani             #+#    #+#             */
/*   Updated: 2024/12/20 23:07:35 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>
//
//char	*ft_strjoin(char const *s1, char const *s2);
//
//int	main(void)
//{
//	char *s1 = "my favorite animal is";
//	char *s2 = " ";
//	char *s3 = "the nyancat";
//	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);
//	printf("%s\n", res);
//	return (0);
//}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		result[i] = s2[i - len1];
		i++;
	}
	return (result);
}
