/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_fun2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 20:23:27 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (n > i)
	{
		str[i] = '\0';
		i += 1;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (0);
	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, (size * count));
	return ((void *)s);
}

int	is_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i += 1;
	}
	return (0);
}

char	*rm_nl(char *s1)
{
	char	*str;
	int		i;

	if (is_nl(s1))
		str = ft_calloc(ft_strlen(s1), 1);
	else
		str = ft_calloc(ft_strlen(s1) + 1, 1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '\n')
			break ;
		str[i] = s1[i];
		i += 1;
	}
	free(s1);
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i += 1;
	}
	return (0);
}
