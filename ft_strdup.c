/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:56:42 by rfani             #+#    #+#             */
/*   Updated: 2024/12/20 23:07:21 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s) + 1);
	if (p != NULL)
		ft_strlcpy(p, s, ft_strlen(s) + 1);
	return (p);
}
