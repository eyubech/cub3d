/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:57:09 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_data(t_cub_data *cb_data, t_map_data *t_map)
{
	t_map->count = 0;
	t_map->line = 1;
	t_map->north_wall = NULL;
	t_map->south_wall = NULL;
	t_map->west_wall = NULL;
	t_map->east_wall = NULL;
	t_map->f_color = NULL;
	t_map->c_color = NULL;
	t_map->error_code = 0;
	t_map->map = NULL;
	t_map->map_size = 0;
	cb_data->map_width = 0;
}

void	init_data_map(t_cub_data *cb_data, t_map_data *t_map)
{
	t_map->i = 0;
	t_map->j = 0;
	t_map->fd = open(cb_data->map_name, O_RDONLY);
	t_map->map_area = 0;
	cb_data->dont_show_map = 0;
}

void	dup_elements(t_map_data *t_map)
{
	if (!ft_strncmp(t_map->readed_splited[0], "NO", 2)
		&& (ft_strlen(t_map->readed_splited[0]) == 2))
	{
		t_map->north_wall = ft_strdup(t_map->readed_splited[1]);
		t_map->north_wall = rm_nl(t_map->north_wall);
	}
	if (!ft_strncmp(t_map->readed_splited[0], "SO", 2)
		&& (ft_strlen(t_map->readed_splited[0]) == 2))
	{
		t_map->south_wall = ft_strdup(t_map->readed_splited[1]);
		t_map->south_wall = rm_nl(t_map->south_wall);
	}
	if (!ft_strncmp(t_map->readed_splited[0], "WE", 2)
		&& (ft_strlen(t_map->readed_splited[0]) == 2))
	{
		t_map->west_wall = ft_strdup(t_map->readed_splited[1]);
		t_map->west_wall = rm_nl(t_map->west_wall);
	}
	if (!ft_strncmp(t_map->readed_splited[0], "EA", 2)
		&& (ft_strlen(t_map->readed_splited[0]) == 2))
	{
		t_map->east_wall = ft_strdup(t_map->readed_splited[1]);
		t_map->east_wall = rm_nl(t_map->east_wall);
	}
}

void	parse_colors(t_cub_data *cb_data, t_map_data *t_map)
{
	if (!ft_strncmp(t_map->readed_splited[0], "F", 1)
		&& (ft_strlen(t_map->readed_splited[0]) == 1))
		parse_f_color(cb_data, t_map);
	if (!ft_strncmp(t_map->readed_splited[0], "C", 1)
		&& (ft_strlen(t_map->readed_splited[0]) == 1))
		parse_c_color(cb_data, t_map);
	free_2d(t_map->readed_splited);
}

void	free_2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i += 1;
	}
	free(s);
}
