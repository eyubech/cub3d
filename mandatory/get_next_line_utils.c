/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:22:56 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i += 1;
	}
	return (i);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	substring = (char *)malloc(sizeof(char) * len + 1);
	while (s[start] != '\0' && i < len)
	{
		substring[i] = s[start];
		i += 1;
		start += 1;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i += 1;
	}
	while (s2[j] != '\0')
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}
