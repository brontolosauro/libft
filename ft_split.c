/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:53:53 by rfani             #+#    #+#             */
/*   Updated: 2024/12/21 12:49:13 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>
//
//char		**ft_split(char const *s, char c);
static char	*chunk(char const *s, int *s_index, char c);

//int	main(void)
//{
////	char	*str = "How are you doing today?";
//	char	*str = "hello!";
//	char	delimiter = ' ';
//	char	**split; 
//	int		i;
//
//	split = ft_split(str, delimiter);
//	i = 0;
//	while (split[i] != NULL)
//	{
//		printf("%s\n", split[i]);
//		i++;
//	}
//	return (0);
//}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		split_index;
	int		s_index;

	if (!s)
		return (NULL);
	split = malloc((ft_strlen(s) / 2 + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split_index = 0;
	s_index = 0;
	while (s[s_index] != '\0' )
	{
		if (s[s_index] != c)
		{
			split[split_index] = chunk(s, &s_index, c);
			split_index++;
		}
		s_index++;
	}
	split[split_index] = NULL;
	return (split);
}

static char	*chunk(char const *s, int *s_index, char c)
{
	char	*chunk;
	int		i;

	chunk = ft_calloc(ft_strlen(s) - *s_index + 1, sizeof(char));
	if (!chunk)
		return (NULL);
	i = 0;
	while (s[*s_index] != c && s[*s_index] != '\0')
	{
		chunk[i] = s[*s_index];
		i++;
		(*s_index)++;
	}
	if (s[*s_index] == '\0')
		(*s_index)--;
	return (chunk);
}
