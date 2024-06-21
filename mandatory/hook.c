/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:58:06 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	w_case(t_cub_data *cb_data)
{
	int	next_step_x;
	int	next_step_y;

	if (mlx_is_key_down(cb_data->mlx, MLX_KEY_W))
	{
		next_step_x = cb_data->c_player.player_x + cb_data->c_player.px_dir;
		next_step_y = cb_data->c_player.player_y;
		update_player_x(cb_data, next_step_x, next_step_y, 0);
		next_step_x = cb_data->c_player.player_x;
		next_step_y = cb_data->c_player.player_y + cb_data->c_player.py_dir;
		update_player_y(cb_data, next_step_x, next_step_y, 0);
		if (cb_data->check_draw_map % 2 == 0 && !cb_data->dont_show_map)
		{
			draw_map(cb_data);
			draw_map_rays(cb_data);
		}
	}
}

void	s_case(t_cub_data *cb_data)
{
	int	next_step_x;
	int	next_step_y;

	if (mlx_is_key_down(cb_data->mlx, MLX_KEY_S))
	{
		next_step_x = cb_data->c_player.player_x - cb_data->c_player.px_dir;
		next_step_y = cb_data->c_player.player_y;
		update_player_x(cb_data, next_step_x, next_step_y, 1);
		next_step_x = cb_data->c_player.player_x;
		next_step_y = cb_data->c_player.player_y - cb_data->c_player.py_dir;
		update_player_y(cb_data, next_step_x, next_step_y, 1);
		if (cb_data->check_draw_map % 2 == 0 && !cb_data->dont_show_map)
		{
			draw_map(cb_data);
			draw_map_rays(cb_data);
		}
	}
}

void	d_case(t_cub_data *cb_data)
{
	int	next_step_x;
	int	next_step_y;

	if (mlx_is_key_down(cb_data->mlx, MLX_KEY_D))
	{
		next_step_x = cb_data->c_player.player_x
			+ cos(cb_data->c_player.rotation_angle + M_PI / 2);
		next_step_y = cb_data->c_player.player_y;
		update_player_x(cb_data, next_step_x, next_step_y, 2);
		next_step_x = cb_data->c_player.player_x;
		next_step_y = cb_data->c_player.player_y
			+ sin(cb_data->c_player.rotation_angle + M_PI / 2);
		update_player_y(cb_data, next_step_x, next_step_y, 2);
		if (cb_data->check_draw_map % 2 == 0 && !cb_data->dont_show_map)
		{
			draw_map(cb_data);
			draw_map_rays(cb_data);
		}
	}
}

void	a_case(t_cub_data *cb_data)
{
	int	next_step_x;
	int	next_step_y;

	if (mlx_is_key_down(cb_data->mlx, MLX_KEY_A))
	{
		next_step_x = cb_data->c_player.player_x
			+ cos(cb_data->c_player.rotation_angle - M_PI / 2);
		next_step_y = cb_data->c_player.player_y;
		update_player_x(cb_data, next_step_x, next_step_y, 3);
		next_step_x = cb_data->c_player.player_x;
		next_step_y = cb_data->c_player.player_y
			+ sin(cb_data->c_player.rotation_angle - M_PI / 2);
		update_player_y(cb_data, next_step_x, next_step_y, 3);
		if (cb_data->check_draw_map % 2 == 0 && !cb_data->dont_show_map)
		{
			draw_map(cb_data);
			draw_map_rays(cb_data);
		}
	}
}

void	ft_hook(void *param)
{
	t_cub_data	*cb_data;

	cb_data = (t_cub_data *)param;
	if (mlx_is_key_down(cb_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cb_data->mlx);
	if (cb_data->pause_game % 2 != 0)
		return ;
	mlx_get_mouse_pos(cb_data->mlx, &cb_data->mouse_x, &cb_data->mouse_y);
	left_case(cb_data);
	right_case(cb_data);
	w_case(cb_data);
	s_case(cb_data);
	d_case(cb_data);
	a_case(cb_data);
	cb_data->offset_mouse_x = cb_data->mouse_x;
}
