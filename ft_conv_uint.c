/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:52:46 by rfani             #+#    #+#             */
/*   Updated: 2025/03/17 11:50:55 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

t_arg	ft_conv_uint(va_list args);

t_arg	ft_conv_uint(va_list args)
{
	t_arg			arg;
	unsigned int	n;
	char			*str;

	n = va_arg(args, unsigned int);
	str = ft_uitoa(n);
	arg.content = str;
	arg.length = ft_strlen(str);
	return (arg);
}
