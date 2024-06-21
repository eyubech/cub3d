/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:47:55 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:24:37 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	found_hole(t_cub_data *cb_data, t_map_data *t_map, int i, int j)
{
	(void)cb_data;
	if ((t_map->map[i][j] == '0' && ((t_map->map[i][j + 1] != '0'
			&& t_map->map[i][j + 1] != '1' && t_map->map[i][j
		+ 1] != 'N' && t_map->map[i][j + 1] != 'E'
					&& t_map->map[i][j + 1] != 'W' && t_map->map[i][j
					+ 1] != 'S') || (t_map->map[i + 1][j] != '0' && t_map->map[i
					+ 1][j] != '1' && t_map->map[i + 1][j] != 'N'
					&& t_map->map[i + 1][j] != 'E' && t_map->map[i
					+ 1][j] != 'W' && t_map->map[i + 1][j] != 'S')
				|| (t_map->map[i - 1][j] != '0' && t_map->map[i - 1][j] != '1'
					&& t_map->map[i - 1][j] != 'N' && t_map->map[i
					- 1][j] != 'E' && t_map->map[i - 1][j] != 'W'
					&& t_map->map[i - 1][j] != 'S') || (t_map->map[i][j
					- 1] != '0' && t_map->map[i][j - 1] != '1'
					&& t_map->map[i][j - 1] != 'N' && t_map->map[i][j
					- 1] != 'E' && t_map->map[i][j - 1] != 'W'
					&& t_map->map[i][j - 1] != 'S'))))
	{
		free_2d(t_map->map);
		show_errors("Invalid map\n");
		exit(2);
	}
}

void	zero_in_borders(t_cub_data *cb_data, t_map_data *t_map, int i, int j)
{
	(void)cb_data;
	if (t_map->map[i][j] == '0' && (!i || (i == t_map->map_size - 1) || !j
			|| (j == ft_strlen(t_map->map[i]) - 1)))
	{
		free_2d(t_map->map);
		show_errors("Invalid map\n");
		exit(2);
	}
}
