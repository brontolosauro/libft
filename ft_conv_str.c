/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:52:41 by rfani             #+#    #+#             */
/*   Updated: 2025/03/26 20:01:45 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "libft.h"

t_arg	ft_conv_str(va_list args);

t_arg	ft_conv_str(va_list args)
{
	t_arg	arg;
	char	*temp;
	char	*str;
	size_t	len;

	temp = va_arg(args, char *);
	if (!temp)
		temp = "(null)";
	str = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	len = ft_strlcpy(str, temp, ft_strlen(temp) + 1);
	arg.content = str;
	arg.length = len;
	return (arg);
}
