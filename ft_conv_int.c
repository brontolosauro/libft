/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:52:28 by rfani             #+#    #+#             */
/*   Updated: 2025/03/17 11:49:56 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

t_arg	ft_conv_int(va_list args);

t_arg	ft_conv_int(va_list args)
{
	t_arg	arg;
	int		n;
	char	*str;

	n = va_arg(args, int);
	str = ft_itoa(n);
	arg.content = str;
	arg.length = ft_strlen(str);
	return (arg);
}
