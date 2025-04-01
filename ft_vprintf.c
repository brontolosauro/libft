/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:39:10 by rfani             #+#    #+#             */
/*   Updated: 2025/03/17 12:01:23 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_vprintf(const char *format, va_list args);

int	ft_vprintf(const char *format, va_list args)
{
	int		count;
	t_arg	arg;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			arg = ft_parse_convspec(&format, args);
			count += ft_print_arg(arg);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	return (count);
}
