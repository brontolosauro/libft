/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:08:46 by rfani             #+#    #+#             */
/*   Updated: 2024/12/20 23:05:40 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*match;
	size_t	i;

	match = NULL;
	i = 0;
	if (!s)
		return (match);
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
		{
			match = ((unsigned char *)s + i);
			break ;
		}
		i++;
	}
	return (match);
}
