/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:30:18 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 20:17:31 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

static int	cn_words(char *s, char c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i += 1;
			ret += 1;
		}
		else
			i += 1;
	}
	return (ret);
}

static char	**while_helper(char *s, char c, char **ret)
{
	int	i;
	int	j;
	int	st;
	int	e;

	i = 0;
	j = 0;
	while ((char)s[i])
	{
		if ((char)s[i] != c)
		{
			st = i;
			while ((char)s[i] != c && s[i])
				i += 1;
			e = i - 1;
			ret[j] = ft_substr(s, st, (e - st) + 1);
			j += 1;
		}
		else
			i += 1;
	}
	ret[j] = 0;
	return (ret);
}

char	**ft_split(char *s, char c)
{
	char	**ret;

	if (!s)
		return (0);
	ret = malloc(sizeof(char *) * (cn_words((char *)s, c) + 1));
	if (!ret)
		return (0);
	ret = while_helper(s, c, ret);
	return (ret);
}
