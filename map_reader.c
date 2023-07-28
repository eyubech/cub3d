/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:31:53 by aech-che          #+#    #+#             */
/*   Updated: 2023/07/28 18:57:46 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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








int	check_erros(t_cub_data *cb_data)
{
	if (suff_error(cb_data))
		return (1);
	return (0);
}

int	read_map(t_cub_data *cb_data)
{
	if (check_erros(cb_data))
		return (-1);
	return (0);
}
