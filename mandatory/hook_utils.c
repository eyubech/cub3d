/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:05:44 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	left_case(t_cub_data *cb_data)
{
	if (mlx_is_key_down(cb_data->mlx, MLX_KEY_LEFT)
		|| ((cb_data->offset_mouse_x > cb_data->mouse_x && cb_data->check_mouse
				% 2 != 0)))
	{
		cb_data->c_player.rotation_angle -= 0.05;
		if (cb_data->c_player.rotation_angle < 0)
			cb_data->c_player.rotation_angle += 2 * M_PI;
		cb_data->c_player.px_dir = cos(cb_data->c_player.rotation_angle) * 5;
		cb_data->c_player.py_dir = sin(cb_data->c_player.rotation_angle) * 5;
		draw_background(cb_data);
		ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x,
			cb_data->c_player.player_y);
		if (cb_data->check_draw_map % 2 == 0 && !cb_data->dont_show_map)
		{
			draw_map(cb_data);
			draw_map_rays(cb_data);
		}
	}
}

void	right_case(t_cub_data *cb_data)
{
	if (mlx_is_key_down(cb_data->mlx, MLX_KEY_RIGHT)
		|| (cb_data->offset_mouse_x < cb_data->mouse_x && cb_data->check_mouse
			% 2 != 0))
	{
		cb_data->c_player.rotation_angle += 0.05;
		if (cb_data->c_player.rotation_angle >= 2 * M_PI)
			cb_data->c_player.rotation_angle -= 2 * M_PI;
		cb_data->c_player.px_dir = cos(cb_data->c_player.rotation_angle) * 5;
		cb_data->c_player.py_dir = sin(cb_data->c_player.rotation_angle) * 5;
		draw_background(cb_data);
		ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x,
			cb_data->c_player.player_y);
		if (cb_data->check_draw_map % 2 == 0 && !cb_data->dont_show_map)
		{
			draw_map(cb_data);
			draw_map_rays(cb_data);
		}
	}
}

int	not_wall(t_cub_data *cb_data, int next_step_x, int next_step_y)
{
	if ((cb_data->map[(next_step_y) / CELL_SIZE][(next_step_x)
			/ CELL_SIZE] != '1') && (((cb_data->map[((next_step_y - 1))
					/ CELL_SIZE][((next_step_x - 1)) / CELL_SIZE] != '1')
				&& (cb_data->map[(next_step_y) / CELL_SIZE][((next_step_x + 1))
					/ CELL_SIZE] != '1')) && ((cb_data->map[((next_step_y))
					/ CELL_SIZE][((next_step_x - 1)) / CELL_SIZE] != '1')
				&& (cb_data->map[(next_step_y + 1) / CELL_SIZE][((next_step_x))
					/ CELL_SIZE] != '1')) && ((cb_data->map[((next_step_y + 1))
					/ CELL_SIZE][((next_step_x)) / CELL_SIZE] != '1')
				&& (cb_data->map[(next_step_y) / CELL_SIZE][((next_step_x + 1))
					/ CELL_SIZE] != '1')) && ((cb_data->map[((next_step_y - 1))
					/ CELL_SIZE][((next_step_x)) / CELL_SIZE] != '1')
				&& (cb_data->map[(next_step_y) / CELL_SIZE][((next_step_x - 1))
					/ CELL_SIZE] != '1'))))
		return (1);
	return (0);
}

void	update_player_x(t_cub_data *cb_data, int next_step_x, int next_step_y,
		int check)
{
	if (not_wall(cb_data, next_step_x, next_step_y))
	{
		if (check == 0)
			cb_data->c_player.player_x += cb_data->c_player.px_dir / 4;
		else if (check == 1)
			cb_data->c_player.player_x -= cb_data->c_player.px_dir / 4;
		else if (check == 2)
			cb_data->c_player.player_x += cos(cb_data->c_player.rotation_angle
					+ M_PI / 2);
		else if (check == 3)
			cb_data->c_player.player_x += cos(cb_data->c_player.rotation_angle
					- M_PI / 2);
		draw_background(cb_data);
		ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x,
			cb_data->c_player.player_y);
	}
}

void	update_player_y(t_cub_data *cb_data, int next_step_x, int next_step_y,
		int check)
{
	if (not_wall(cb_data, next_step_x, next_step_y))
	{
		if (check == 0)
			cb_data->c_player.player_y += cb_data->c_player.py_dir / 4;
		else if (check == 1)
			cb_data->c_player.player_y -= cb_data->c_player.py_dir / 4;
		else if (check == 2)
			cb_data->c_player.player_y += sin(cb_data->c_player.rotation_angle
					+ M_PI / 2);
		else if (check == 3)
			cb_data->c_player.player_y += sin(cb_data->c_player.rotation_angle
					- M_PI / 2);
		draw_background(cb_data);
		ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x,
			cb_data->c_player.player_y);
	}
}
