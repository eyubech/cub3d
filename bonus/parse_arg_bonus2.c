/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:15:34 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 21:15:54 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	parse_f_color_help(t_cub_data *cb_data, t_map_data *t_map)
{
	cb_data->f_red = ft_atoi(t_map->f_color[0]);
	cb_data->f_green = ft_atoi(t_map->f_color[1]);
	cb_data->f_blue = ft_atoi(t_map->f_color[2]);
	if (cb_data->f_red > 255 || cb_data->f_green > 255 || cb_data->f_blue > 255)
	{
		free_2d(t_map->f_color);
		show_errors("Bad value at f color\n");
		exit(2);
	}
}

void	parse_f_color(t_cub_data *cb_data, t_map_data *t_map)
{
	t_map->readed_splited[1] = rm_nl(t_map->readed_splited[1]);
	t_map->f_color = ft_split(t_map->readed_splited[1], ',');
	if (count_el(t_map->f_color) != 3)
	{
		free_2d(t_map->f_color);
		show_errors("Bad value at f color\n");
		exit(2);
	}
	t_map->i = 0;
	t_map->counter = 0;
	while (t_map->readed_splited[1][t_map->i])
	{
		if (t_map->readed_splited[1][t_map->i] == ',')
			t_map->counter += 1;
		if ((!ft_isdigit(t_map->readed_splited[1][t_map->i])
			&& t_map->readed_splited[1][t_map->i] != ',')
			|| t_map->counter > 2)
		{
			free_2d(t_map->f_color);
			show_errors("Bad value at f color\n");
			exit(2);
		}
		t_map->i += 1;
	}
	parse_f_color_help(cb_data, t_map);
}

void	parse_c_color_help(t_cub_data *cb_data, t_map_data *t_map)
{
	cb_data->c_red = ft_atoi(t_map->c_color[0]);
	cb_data->c_green = ft_atoi(t_map->c_color[1]);
	cb_data->c_blue = ft_atoi(t_map->c_color[2]);
	if (cb_data->c_red > 255 || cb_data->c_green > 255 || cb_data->c_blue > 255)
	{
		free_2d(t_map->c_color);
		show_errors("Bad value at c color\n");
		exit(2);
	}
}

void	parse_c_color(t_cub_data *cb_data, t_map_data *t_map)
{
	t_map->readed_splited[1] = rm_nl(t_map->readed_splited[1]);
	t_map->c_color = ft_split(t_map->readed_splited[1], ',');
	if (count_el(t_map->c_color) != 3)
	{
		free_2d(t_map->c_color);
		show_errors("Bad value at c color\n");
		exit(2);
	}
	t_map->i = 0;
	t_map->counter = 0;
	while (t_map->readed_splited[1][t_map->i])
	{
		if (t_map->readed_splited[1][t_map->i] == ',')
			t_map->counter += 1;
		if ((!ft_isdigit(t_map->readed_splited[1][t_map->i])
			&& t_map->readed_splited[1][t_map->i] != ',')
			|| t_map->counter > 2)
		{
			free_2d(t_map->c_color);
			show_errors("Bad value at c color\n");
			exit(2);
		}
		t_map->i += 1;
	}
	parse_c_color_help(cb_data, t_map);
}
