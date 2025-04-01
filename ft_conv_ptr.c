/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:52:37 by rfani             #+#    #+#             */
/*   Updated: 2025/03/27 11:52:20 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

t_arg	ft_conv_ptr(va_list args);

t_arg	ft_conv_ptr(va_list args)
{
	t_arg				arg;
	unsigned long int	n;
	char				*str;
	char				*prefix;
	char				*temp;

	n = (unsigned long int)va_arg(args, void *);
	if (!n)
	{
		prefix = "(nil)";
		str = ft_calloc(ft_strlen(prefix) + 1, sizeof(char));
		ft_strlcpy(str, prefix, ft_strlen(prefix) + 1);
	}
	else
	{
		prefix = "0x";
		temp = ft_lxitoa(n);
		str = ft_strjoin(prefix, temp);
		free(temp);
	}
	arg.content = str;
	arg.length = ft_strlen(str);
	return (arg);
}
