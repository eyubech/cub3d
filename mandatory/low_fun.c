/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:04:31 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	sub_str(char *s1, char *set)
{
	int	i;
	int	j;

	j = ft_strlen(s1);
	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i += 1;
	}
	if (i == j)
		return (i);
	return (0);
}

static int	suf_str(char *s1, char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i)
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i -= 1;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	p;
	int	s;

	if (!s1 || !set)
		return (NULL);
	p = sub_str((char *)s1, (char *)set);
	s = suf_str((char *)s1, (char *)set);
	if (p == (int)ft_strlen(s1))
		return (ft_substr(s1, p, 0));
	return (ft_substr(s1, p, (s - p) + 1));
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i += 1;
	}
	return (NULL);
}

void	show_errors(char *message)
{
	int	i;

	i = 0;
	write(STDERR_FILENO, "Error!!\n", 8);
	while (message[i])
	{
		write(2, &message[i], 1);
		i += 1;
	}
}
