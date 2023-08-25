/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:03:06 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/25 19:15:57 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_map_rays(t_cub_data *cb_data)
{
	int	index;

	index = 0;
	while (index < NUM_RAYS)
	{
		if (cb_data->sr[index].hor_dist <= cb_data->sr[index].ver_dist)
			draw_line(cb_data->sr[index].x, cb_data->sr[index].y,
				cb_data->sr[index].hx_inter, cb_data->sr[index].hy_inter,
				cb_data);
		else
			draw_line(cb_data->sr[index].x, cb_data->sr[index].y,
				cb_data->sr[index].vx_inter, cb_data->sr[index].vy_inter,
				cb_data);
		index += 1;
	}
}

void	initialize_vars(t_cub_data *cb_data, int index)
{
	cb_data->tex.alpha = cb_data->sr[index].ray_angle
		- cb_data->sr[index].player_rotation_angle;
	cb_data->tex.corr_dist = cb_data->sr[index].r_distance * 
		cos(cb_data->tex.alpha);
	cb_data->tex.pro_dist = (WIDTH / 2) / tan(FOV / 2);
	cb_data->tex.pro_height = (CELL_SIZE / cb_data->tex.corr_dist) * 
		cb_data->tex.pro_dist;
	cb_data->tex.start = HEIGHT / 2 - cb_data->tex.pro_height / 2;
	if (cb_data->tex.start < 0)
		cb_data->tex.start = 0;
	cb_data->tex.offset_y = 0;
	cb_data->tex.offset_x = 0;
	cb_data->tex.step = cb_data->north_wall->height / cb_data->tex.pro_height;
	cb_data->tex.e = cb_data->tex.pro_height / 2 - HEIGHT / 2;
	if (cb_data->tex.e < 0)
		cb_data->tex.e = 0;
}

void	set_offset(t_cub_data *cb_data, int index)
{
	if (cb_data->sr[index].hit_side == 0)
		cb_data->tex.offset_x = (int)(cb_data->sr[index].hx_inter
				* cb_data->north_wall->width / CELL_SIZE)
			% cb_data->north_wall->width;
	else if (cb_data->sr[index].hit_side == 1)
		cb_data->tex.offset_x = (int)(cb_data->sr[index].vy_inter
				* cb_data->north_wall->width / CELL_SIZE)
			% cb_data->north_wall->width;
	if ((sin(cb_data->sr[index].ray_angle) > 0 && 
			cb_data->sr[index].hit_side == 0) || 
		(cos(cb_data->sr[index].ray_angle) < 0 && 
			cb_data->sr[index].hit_side == 1))
		cb_data->tex.offset_x = cb_data->north_wall->width - 
			cb_data->tex.offset_x;
	cb_data->tex.offset_y = cb_data->tex.step * cb_data->tex.e;
}

void	put_pixel(t_cub_data *cb_data, int index, int y)
{
	if (sin(cb_data->sr[index].ray_angle) < 0 && 
		cb_data->sr[index].hit_side == 0)
		mlx_put_pixel(cb_data->map_img, index, cb_data->tex.start + y,
			cb_data->north_texture[((int)cb_data->tex.offset_y
				* cb_data->north_wall->width) + (int)cb_data->tex.offset_x]);
	else if (sin(cb_data->sr[index].ray_angle) > 0 && 
		cb_data->sr[index].hit_side == 0)
	{
		mlx_put_pixel(cb_data->map_img, index, cb_data->tex.start + y,
			cb_data->south_texture[((int)cb_data->tex.offset_y
				* cb_data->south_wall->width) + (int)cb_data->tex.offset_x]);
	}
	else if (cos(cb_data->sr[index].ray_angle) > 0 && 
		cb_data->sr[index].hit_side == 1)
		mlx_put_pixel(cb_data->map_img, index, cb_data->tex.start + y,
			cb_data->east_texture[((int)cb_data->tex.offset_y
				* cb_data->east_wall->width) + (int)cb_data->tex.offset_x]);
	else if (cos(cb_data->sr[index].ray_angle) < 0 && 
		cb_data->sr[index].hit_side == 1)
		mlx_put_pixel(cb_data->map_img, index, cb_data->tex.start + y,
			cb_data->west_texture[((int)cb_data->tex.offset_y
				* cb_data->west_wall->width) + (int)cb_data->tex.offset_x]); 
}

void	draw_wall(t_cub_data *cb_data, int index)
{
	int	y;

	y = 0;
	while (y < (int)cb_data->tex.pro_height && y < HEIGHT)
	{
		put_pixel(cb_data, index, y); 
		cb_data->tex.offset_y += cb_data->tex.step;
		y++;
	}
}
