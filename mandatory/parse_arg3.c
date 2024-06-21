/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:27:59 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	map_errors_msg(t_map_data *t_map)
{
	if (!t_map->north_wall || !t_map->south_wall || !t_map->west_wall
		|| !t_map->east_wall || !t_map->f_color || !t_map->c_color)
	{
		show_errors("Try to add all elements\n");
		exit(2);
	}
	if (!t_map->map)
	{
		show_errors("No map founded\n");
		exit(2);
	}
	if (t_map->error_code)
		exit(2);
}

void	check_count(t_map_data *t_map)
{
	if (t_map->count < 6)
	{
		show_errors("To few Arguments\n");
		free(t_map->readed);
		exit(2);
	}
	t_map->map_size += 1;
	free(t_map->readed);
}

void	count_map_size(t_cub_data *cb_data, t_map_data *t_map)
{
	check_count(t_map);
	while (1)
	{
		t_map->readed = get_next_line(cb_data->map_fd);
		if (!t_map->readed)
			break ;
		if (ft_strlen(t_map->readed) > cb_data->map_width)
			cb_data->map_width = ft_strlen(t_map->readed);
		t_map->map_size += 1;
		free(t_map->readed);
	}
}

void	helping_parse(t_cub_data *cb_data, t_map_data *t_map)
{
	t_map->readed_splited = ft_split(t_map->readed, ' ');
	if (count_el(t_map->readed_splited) > 2)
	{
		show_errors("To much Arguments here in line: ");
		printf("%d\n", t_map->line);
		t_map->error_code = 1;
	}
	t_map->count += 1;
	if ((!t_map->north_wall || !t_map->south_wall || !t_map->west_wall
			|| !t_map->east_wall || !t_map->f_color || !t_map->c_color)
		&& t_map->count > 6)
	{
		show_errors("Weird map, use a simple one please :)\n");
		t_map->error_code = 1;
	}
	dup_elements(t_map);
	parse_colors(cb_data, t_map);
}
