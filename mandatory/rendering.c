/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:57:39 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_map_rays(t_cub_data *cb_data)
{
	int	index;

	index = 0;
	while (index < NUM_RAYS)
	{
		if (cb_data->sr[index].hor_dist <= cb_data->sr[index].ver_dist)
			draw_line_hor(cb_data, index);
		else
			draw_line_ver(cb_data, index);
		index += 1;
	}
}

void	set_sizes(t_cub_data *cb_data, int index)
{
	if (sin(cb_data->sr[index].ray_angle) < 0
		&& cb_data->sr[index].hit_side == 0)
	{
		cb_data->tex.width = cb_data->north_wall->width;
		cb_data->tex.height = cb_data->north_wall->height;
	}
	else if (sin(cb_data->sr[index].ray_angle) > 0
		&& cb_data->sr[index].hit_side == 0)
	{
		cb_data->tex.width = cb_data->south_wall->width;
		cb_data->tex.height = cb_data->south_wall->height;
	}
	else if (cos(cb_data->sr[index].ray_angle) > 0
		&& cb_data->sr[index].hit_side == 1)
	{
		cb_data->tex.width = cb_data->east_wall->width;
		cb_data->tex.height = cb_data->east_wall->height;
	}
	else if (cos(cb_data->sr[index].ray_angle) < 0
		&& cb_data->sr[index].hit_side == 1)
	{
		cb_data->tex.width = cb_data->west_wall->width;
		cb_data->tex.height = cb_data->west_wall->height;
	}
}

void	initialize_vars(t_cub_data *cb_data, int index)
{
	cb_data->tex.alpha = cb_data->sr[index].ray_angle
		- cb_data->sr[index].player_rotation_angle;
	cb_data->tex.corr_dist = cb_data->sr[index].r_distance
		* cos(cb_data->tex.alpha);
	cb_data->tex.pro_dist = (WIDTH / 2) / tan(FOV / 2);
	cb_data->tex.pro_height = (CELL_SIZE / cb_data->tex.corr_dist)
		* cb_data->tex.pro_dist;
	if (cb_data->tex.pro_height < 20)
		cb_data->tex.pro_height = 20;
	cb_data->tex.start = HEIGHT / 2 - cb_data->tex.pro_height / 2;
	if (cb_data->tex.start < 0)
		cb_data->tex.start = 0;
	cb_data->tex.offset_y = 0;
	cb_data->tex.offset_x = 0;
}

void	set_offset(t_cub_data *cb_data, int index)
{
	if (cb_data->sr[index].hit_side == 0)
		cb_data->tex.offset_x = (int)(cb_data->sr[index].hx_inter
				* cb_data->tex.width / CELL_SIZE) % cb_data->tex.width;
	else if (cb_data->sr[index].hit_side == 1)
		cb_data->tex.offset_x = (int)(cb_data->sr[index].vy_inter
				* cb_data->tex.width / CELL_SIZE) % cb_data->tex.width;
	if ((sin(cb_data->sr[index].ray_angle) > 0
			&& cb_data->sr[index].hit_side == 0)
		|| (cos(cb_data->sr[index].ray_angle) < 0
			&& cb_data->sr[index].hit_side == 1))
		cb_data->tex.offset_x = cb_data->tex.width
			- cb_data->tex.offset_x;
	cb_data->tex.step = cb_data->tex.height / cb_data->tex.pro_height;
	cb_data->tex.e = cb_data->tex.pro_height / 2 - HEIGHT / 2;
	if (cb_data->tex.e < 0)
		cb_data->tex.e = 0;
	cb_data->tex.offset_y = cb_data->tex.step * cb_data->tex.e;
}

void	put_pixel(t_cub_data *cb_data, int index, int y)
{
	if (sin(cb_data->sr[index].ray_angle) < 0
		&& cb_data->sr[index].hit_side == 0)
		mlx_put_pixel(cb_data->map_img, index, cb_data->tex.start
			+ y, cb_data->north_texture[((int)cb_data->tex.offset_y
				* cb_data->tex.width) + (int)cb_data->tex.offset_x]);
	else if (sin(cb_data->sr[index].ray_angle) > 0
		&& cb_data->sr[index].hit_side == 0)
	{
		mlx_put_pixel(cb_data->map_img, index, cb_data->tex.start + y,
			cb_data->south_texture[((int)cb_data->tex.offset_y
				* cb_data->tex.width) + (int)cb_data->tex.offset_x]);
	}
	else if (cos(cb_data->sr[index].ray_angle) > 0
		&& cb_data->sr[index].hit_side == 1)
		mlx_put_pixel(cb_data->map_img, index, cb_data->tex.start
			+ y, cb_data->east_texture[((int)cb_data->tex.offset_y
				* cb_data->tex.width) + (int)cb_data->tex.offset_x]);
	else if (cos(cb_data->sr[index].ray_angle) < 0
		&& cb_data->sr[index].hit_side == 1)
		mlx_put_pixel(cb_data->map_img, index, cb_data->tex.start + y,
			cb_data->west_texture[((int)cb_data->tex.offset_y
				* cb_data->tex.width) + (int)cb_data->tex.offset_x]);
}
