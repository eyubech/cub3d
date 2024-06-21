/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:22:59 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	index_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i += 1;
	}
	return (-1);
}

int	this_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i += 1;
	}
	return (0);
}

char	*helper(int y, char **ret, char **save, char **readed)
{
	if (y == -1)
	{
		free(*readed);
		return (NULL);
	}
	if (*readed[0] == '\0')
	{
		*save = NULL;
		free(*readed);
		return (0);
	}
	if (y == 0)
	{
		*ret = ft_strdup(*readed);
		*save = NULL;
	}
	else
	{
		*ret = ft_substr(*readed, 0, index_newline(*readed) + 1);
		*save = ft_strdup(*readed + index_newline(*readed) + 1);
	}
	free(*readed);
	return (*ret);
}

char	*get_next_line(int fd)
{
	int			y;
	char		*buff;
	static char	*save;
	char		*readed;
	char		*ret;

	if (fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	buff = malloc(1 + 1);
	readed = ft_strjoin(save, "");
	while (!this_newline(readed))
	{
		y = read(fd, buff, 1);
		if (y == 0)
			break ;
		if (y == -1)
		{
			save = NULL;
			break ;
		}
		buff[y] = '\0';
		readed = ft_strjoin(readed, buff);
	}
	free(buff);
	return (helper(y, &ret, &save, &readed));
}
