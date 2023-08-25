/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:10:38 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/25 15:38:10 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void parse_map(t_cub_data *cb_data, t_map_data *t_map)
{
	while (1)
	{
		t_map->readed = get_next_line(cb_data->map_fd);
		printf("** %s\n", t_map->readed);
			exit(0);
		if(t_map->readed[0] != '\n' && t_map->readed[0] != '\0')
		{
			printf("** %s\n", t_map->readed);
		}
	}
	
}


void fill_map(t_cub_data *cb_data)
{
	t_map_data *t_map;
	
    cb_data->map_fd = open(cb_data->map_name, O_RDONLY);
	// parse_map(cb_data, t_map);
	if(cb_data->map_fd == -1)
	{
		show_errors("Error while opening the file");
		exit(2);
	}
	
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


int	check_erros(t_cub_data *cb_data)
{
	if (suff_error(cb_data))
		return (1);
	return (0);
}