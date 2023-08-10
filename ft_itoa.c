/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:43:18 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/08 09:51:07 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	len_num(int n)
{
	int	c;

	c = 0;
	if (n < 0)
	{
		n *= -1;
		c += 1;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		c += 1;
	}
	return (c);
}

static unsigned long int	pow_num(int n)
{
	unsigned long int	p;

	p = 1;
	if (n == 0)
		return (10);
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		p *= 10;
		n /= 10;
	}
	return (p / 10);
}

static char	*while_help(char *str, unsigned int tmp, int n, int c)
{
	int	p;
	int	i;

	p = pow_num(tmp);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i += 1;
	}
	while (c-- > 0)
	{
		str[i++] = (tmp / p) + '0';
		tmp %= p;
		p /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				c;
	int				p;
	unsigned int	tmp;

	p = pow_num(n);
	c = len_num(n);
	str = malloc(c + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		tmp = n * -1;
		c -= 1;
	}
	else
		tmp = n;
	while_help(str, tmp, n, c);
	return (str);
}
