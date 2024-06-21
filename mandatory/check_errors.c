/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:10:38 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:42:33 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	search_for_player(t_cub_data *cb_data, t_map_data *t_map)
{
	t_map->y = 0;
	t_map->c = 0;
	while (cb_data->map[t_map->y])
	{
		t_map->j = 0;
		while (cb_data->map[t_map->y][t_map->j])
		{
			if ((is_player(cb_data->map[t_map->y][t_map->j])) && (!t_map->y
					|| (t_map->y == t_map->map_size - 1) || !t_map->j
					|| (t_map->j == ft_strlen(t_map->map[t_map->y]) - 1)))
				player_error_exit(cb_data);
			if (player_open_world(cb_data, t_map, t_map->y, t_map->j))
				player_error_exit(cb_data);
			if (is_player(cb_data->map[t_map->y][t_map->j]))
			{
				init_player(cb_data, t_map, t_map->y, t_map->j);
				t_map->c += 1;
			}
			t_map->j += 1;
		}
		t_map->y += 1;
	}
	if (!t_map->c || t_map->c > 1)
		player_error_exit(cb_data);
}

void	check_map(t_cub_data *cb_data, t_map_data *t_map)
{
	t_map->i = 0;
	check_big_small_map(cb_data, t_map);
	check_game_map(t_map);
	t_map->i = 0;
	while (t_map->map[t_map->i])
	{
		t_map->j = 0;
		while (t_map->map[t_map->i][t_map->j])
		{
			zero_in_borders(cb_data, t_map, t_map->i, t_map->j);
			found_hole(cb_data, t_map, t_map->i, t_map->j);
			t_map->j += 1;
		}
		t_map->i += 1;
	}
}

void	parse_map(t_cub_data *cb_data, t_map_data *t_map)
{
	init_data_map(cb_data, t_map);
	while (1)
	{
		t_map->s = get_next_line(t_map->fd);
		if (!t_map->s)
			break ;
		if (is_map_begin(t_map->s))
			t_map->map_area = 1;
		if (t_map->map_area)
		{
			t_map->s = rm_nl(t_map->s);
			t_map->map[t_map->i] = ft_calloc(sizeof(char), cb_data->map_width);
			t_map->j = 0;
			while (t_map->s[t_map->j])
			{
				t_map->map[t_map->i][t_map->j] = t_map->s[t_map->j];
				t_map->j += 1;
			}
			t_map->i += 1;
		}
		free(t_map->s);
	}
	check_map(cb_data, t_map);
	cb_data->map_width *= CELL_SIZE;
	cb_data->map_height = t_map->map_size * CELL_SIZE;
}

void	parse_arg(t_cub_data *cb_data, t_map_data *t_map)
{
	while (1)
	{
		t_map->readed = get_next_line(cb_data->map_fd);
		if (!t_map->readed)
			break ;
		if (t_map->readed[0] != '\n')
		{
			if (is_map_begin(t_map->readed))
			{
				count_map_size(cb_data, t_map);
				if (t_map->map_size < 3)
				{
					show_errors("Short map!!!!!!!!!\n");
					break ;
				}
				t_map->map = ft_calloc(sizeof(char *), t_map->map_size + 1);
				parse_map(cb_data, t_map);
				break ;
			}
			helping_parse(cb_data, t_map);
		}
		free(t_map->readed);
		t_map->line += 1;
	}
	map_errors_msg(t_map);
}

int	check_erros(t_cub_data *cb_data)
{
	if (suff_error(cb_data))
		return (1);
	return (0);
}
