/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:11:18 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:23:00 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	init_player(t_cub_data *cb_data, t_map_data *t_map, int i, int j)
{
	(void)t_map;
	cb_data->c_player.player_x = (j * CELL_SIZE) + CELL_SIZE / 2;
	cb_data->c_player.player_y = (i * CELL_SIZE) + CELL_SIZE / 2;
	if (cb_data->map[i][j] == 'N')
		cb_data->c_player.rotation_angle = -M_PI_2;
	if (cb_data->map[i][j] == 'S')
		cb_data->c_player.rotation_angle = M_PI_2;
	if (cb_data->map[i][j] == 'E')
		cb_data->c_player.rotation_angle = 0;
	if (cb_data->map[i][j] == 'W')
		cb_data->c_player.rotation_angle = M_PI;
}

int	player_open_world(t_cub_data *cb_data, t_map_data *t_map, int i, int j)
{
	(void)cb_data;
	if (((t_map->map[i][j] == 'N' || t_map->map[i][j] == 'E'
		|| t_map->map[i][j] == 'S' || t_map->map[i][j] == 'W')
			&& ((t_map->map[i][j + 1] != '0' && t_map->map[i][j + 1] != '1')
				|| (t_map->map[i + 1][j] != '0' && t_map->map[i + 1][j] != '1')
				|| (t_map->map[i - 1][j] != '0' && t_map->map[i - 1][j] != '1')
				|| (t_map->map[i][j - 1] != '0' && t_map->map[i][j
					- 1] != '1'))))
		return (1);
	return (0);
}

void	player_error_exit(t_cub_data *cb_data)
{
	show_errors("Please put the player in closed zone or put one\n");
	free_2d(cb_data->map);
	exit(2);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
