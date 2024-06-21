/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:51:12 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

static int	is_space(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i += 1;
		return (i);
	}
	return (0);
}

static int	helper_return(char *str, int i, int sign)
{
	int	res;

	res = 0;
	if (ft_isdigit((char)str[i]))
	{
		while (ft_isdigit((char)str[i]))
		{
			res = res * 10 + (char)str[i] - '0';
			i += 1;
		}
		return (res * sign);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while ((char)str[i])
	{
		i = is_space((char *)str);
		if ((char)str[i] == '-' || (char)str[i] == '+')
		{
			if ((char)str[i] == '-')
				sign *= -1;
			i += 1;
		}
		return (helper_return((char *)str, i, sign));
	}
	return (0);
}
