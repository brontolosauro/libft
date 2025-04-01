/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:22:12 by rfani             #+#    #+#             */
/*   Updated: 2025/03/25 16:47:51 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char		*get_next_line(int fd);
static int	scan_buff(t_list **line_lst, char *buffer, ssize_t *buff_index,
				ssize_t buff_size);
static void	store_item(t_list **line_lst, char buff_item);
static char	*lst_to_str(t_list **line_lst, char *buffer);

char	*get_next_line(int fd)
{
	static char		*buffer;
	static ssize_t	buff_size;
	static ssize_t	buff_index;
	t_list			*line_lst;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		if (!buffer)
			return (NULL);
		buff_size = read(fd, buffer, BUFFER_SIZE);
	}
	line_lst = NULL;
	while (scan_buff(&line_lst, buffer, &buff_index, buff_size))
	{
		buff_size = read(fd, buffer, BUFFER_SIZE);
		buff_index = 0;
		if (BUFFER_SIZE == 1 && buff_size == 0)
			break ;
	}
	return (lst_to_str(&line_lst, buffer));
}

static int	scan_buff(
	t_list **line_lst, char *buffer, ssize_t *buff_index, ssize_t buff_size)
{
	if (buff_size == 0)
		return (0);
	if (buff_size < 0)
		return (ft_lstclear(line_lst, free), 0);
	while (*buff_index < buff_size)
	{
		store_item(line_lst, buffer[*buff_index]);
		if (buffer[*buff_index] == '\n')
		{
			(*buff_index)++;
			return (0);
		}
		(*buff_index)++;
	}
	if (buff_size == *buff_index)
		return (1);
	return (0);
}

static void	store_item(t_list **line_lst, char buff_item)
{
	char	*item;
	t_list	*tail;

	item = (char *)ft_calloc(1 + 1, sizeof(char));
	*item = buff_item;
	tail = ft_lstnew(item);
	ft_lstadd_back(line_lst, tail);
}

static char	*lst_to_str(t_list **line_lst, char *buffer)
{
	char		*line_str;
	t_list		*temp;
	long int	i;
	long int	lst_size;

	if (!*line_lst)
		return (free(buffer), NULL);
	lst_size = ft_lstsize(*line_lst);
	line_str = (char *)ft_calloc((ssize_t)lst_size + 1, sizeof(char));
	if (!line_str)
		return (free(buffer), NULL);
	i = 0;
	temp = *line_lst;
	while (temp)
	{
		line_str[i] = *((char *)temp->content);
		temp = temp->next;
		i++;
	}
	ft_lstclear(line_lst, free);
	return (line_str);
}
