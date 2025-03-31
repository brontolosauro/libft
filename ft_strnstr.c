/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:59:58 by rfani             #+#    #+#             */
/*   Updated: 2024/12/20 23:08:39 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;

	if (!big || !little)
		return (NULL);
	i = 0;
	j = 0;
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *) &big[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
