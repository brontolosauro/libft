/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:52:16 by rfani             #+#    #+#             */
/*   Updated: 2025/03/26 20:02:52 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

t_arg	ft_conv_char(va_list args);

t_arg	ft_conv_char(va_list args)
{
	t_arg	arg;
	char	*str;

	str = ft_calloc(2, sizeof(char));
	*str = (char)va_arg(args, int);
	if (*str == '\0')
	{
		arg.content = str;
		arg.length = 1;
	}
	else
	{
		arg.content = str;
		arg.length = ft_strlen(str);
	}
	return (arg);
}
