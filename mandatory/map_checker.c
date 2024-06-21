/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:18:04 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	unknown_char_exit(t_map_data *t_map)
{
	free_2d(t_map->map);
	show_errors("Unknown char in the map\n");
	exit(2);
}

void	check_big_small_map(t_cub_data *cb_data, t_map_data *t_map)
{
	if (t_map->map_size < 3 || cb_data->map_width < 3)
	{
		free_2d(t_map->map);
		show_errors("Map to small\n");
		exit(2);
	}
	if (cb_data->map_width > (WIDTH - 20) || cb_data->map_height > HEIGHT)
	{
		printf("Be careful next time we're not rockstar\n");
		cb_data->dont_show_map = 1;
	}
}

int	unknown_char(t_map_data *t_map)
{
	if ((t_map->map[t_map->i][t_map->j] != '0'
		&& t_map->map[t_map->i][t_map->j] != '1'
			&& t_map->map[t_map->i][t_map->j] != 'N'
			&& t_map->map[t_map->i][t_map->j] != 'S'
			&& t_map->map[t_map->i][t_map->j] != 'E'
			&& t_map->map[t_map->i][t_map->j] != 'W'
			&& t_map->map[t_map->i][t_map->j] != ' '))
		return (1);
	return (0);
}

void	check_game_map(t_map_data *t_map)
{
	while (t_map->map[t_map->i])
	{
		t_map->j = 0;
		t_map->valid_line = 0;
		while (t_map->map[t_map->i][t_map->j])
		{
			if (unknown_char(t_map))
				unknown_char_exit(t_map);
			if (t_map->map[t_map->i][t_map->j] == '0'
				|| t_map->map[t_map->i][t_map->j] == '1'
				|| is_player(t_map->map[t_map->i][t_map->j]))
				t_map->valid_line += 1;
			t_map->j += 1;
		}
		if (!t_map->valid_line)
		{
			free_2d(t_map->map);
			show_errors("Empty or invalid line\n");
			exit(2);
		}
		t_map->i += 1;
	}
}
