/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_chex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:52:25 by rfani             #+#    #+#             */
/*   Updated: 2025/03/17 23:03:38 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

t_arg	ft_conv_chex(va_list args);

t_arg	ft_conv_chex(va_list args)
{
	t_arg			arg;
	unsigned int	n;
	char			*str;
	int				str_len;
	int				i;

	n = va_arg(args, unsigned int);
	str = ft_xitoa(n);
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		str[i] = (char)ft_toupper((int)str[i]);
		i++;
	}
	arg.content = str;
	arg.length = ft_strlen(str);
	return (arg);
}
