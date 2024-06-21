/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:04:17 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/31 22:37:23 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	case_one(struct mlx_key_data key_data, t_cub_data *cb_data)
{
	if (key_data.key == MLX_KEY_M && key_data.action == 0)
	{
		if (cb_data->check_draw_map % 2 == 0)
		{
			draw_background(cb_data);
			ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x,
				cb_data->c_player.player_y);
			if (cb_data->pause_game % 2 != 0)
				draw_pause_icon(cb_data);
		}
		else
		{
			if (!cb_data->dont_show_map)
			{
				draw_map(cb_data);
				draw_map_rays(cb_data);
			}
			if (cb_data->pause_game % 2 != 0)
				draw_pause_icon(cb_data);
		}
		cb_data->check_draw_map += 1;
	}
}

void	case_two(struct mlx_key_data key_data, t_cub_data *cb_data)
{
	if (key_data.key == MLX_KEY_C && key_data.action == 0)
	{
		if (cb_data->check_mouse % 2 == 0)
			mlx_set_cursor_mode(cb_data->mlx, MLX_MOUSE_DISABLED);
		else
			mlx_set_cursor_mode(cb_data->mlx, MLX_MOUSE_NORMAL);
		cb_data->check_mouse += 1;
	}
}

void	case_three(struct mlx_key_data key_data, t_cub_data *cb_data)
{
	if (key_data.key == MLX_KEY_P && key_data.action == 0)
	{
		if (cb_data->pause_game % 2 == 0)
			draw_pause_icon(cb_data);
		else
		{
			draw_background(cb_data);
			ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x,
				cb_data->c_player.player_y);
			if (cb_data->check_draw_map % 2 == 0 && !cb_data->dont_show_map)
			{
				draw_map(cb_data);
				draw_map_rays(cb_data);
			}
		}
		cb_data->pause_game += 1;
	}
}

void	show_map(struct mlx_key_data key_data, void *param)
{
	t_cub_data	*cb_data;

	cb_data = (t_cub_data *)param;
	case_one(key_data, cb_data);
	case_two(key_data, cb_data);
	case_three(key_data, cb_data);
}
