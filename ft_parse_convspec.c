/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_convspec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:12:02 by rfani             #+#    #+#             */
/*   Updated: 2025/03/17 11:56:36 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

t_arg	ft_parse_convspec(const char **format, va_list args);

t_arg	ft_parse_convspec(const char **format, va_list args)
{
	t_arg	arg;

	arg.content = NULL;
	arg.length = 0;
	if (*(*format) == 'c')
		arg = ft_conv_char(args);
	if (*(*format) == 's')
		arg = ft_conv_str(args);
	if (*(*format) == 'p')
		arg = ft_conv_ptr(args);
	if (*(*format) == 'd')
		arg = ft_conv_int(args);
	if (*(*format) == 'i')
		arg = ft_conv_int(args);
	if (*(*format) == 'u')
		arg = ft_conv_uint(args);
	if (*(*format) == 'x')
		arg = ft_conv_hex(args);
	if (*(*format) == 'X')
		arg = ft_conv_chex(args);
	if (*(*format) == '%')
		arg = ft_conv_percent();
	return (arg);
}
