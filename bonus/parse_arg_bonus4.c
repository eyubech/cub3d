/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_bonus4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:46:05 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 21:16:37 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

int	count_el(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

int	is_map_begin(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '1' || s[0] == '0' || s[0] == ' ')
		return (1);
	return (0);
}

void	fill_map(t_cub_data *cb_data, t_map_data *t_map)
{
	cb_data->map_fd = open(cb_data->map_name, O_RDONLY);
	if (cb_data->map_fd == -1)
	{
		show_errors("Error while opening the file");
		exit(2);
	}
	init_data(cb_data, t_map);
	parse_arg(cb_data, t_map);
}

int	suff_error(t_cub_data *cb_data)
{
	int	i;

	i = 0;
	while (cb_data->map_name[i])
	{
		if (cb_data->map_name[i] == '.' && i)
		{
			if (cb_data->map_name[i + 1] == 'c' && cb_data->map_name[i
					+ 2] == 'u' && cb_data->map_name[i + 3] == 'b'
				&& !cb_data->map_name[i + 4])
				return (0);
		}
		i += 1;
	}
	show_errors("file suffix must to be .cub\n");
	return (1);
}
