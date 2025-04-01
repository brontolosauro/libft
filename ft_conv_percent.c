/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:52:33 by rfani             #+#    #+#             */
/*   Updated: 2025/03/26 18:18:00 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arg	ft_conv_percent(void);

t_arg	ft_conv_percent(void)
{
	t_arg	arg;
	char	*str;

	str = ft_calloc(2, sizeof(char));
	str[0] = '%';
	arg.content = str;
	arg.length = 1;
	return (arg);
}
