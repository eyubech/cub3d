/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:06:23 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	cast_horizontal(t_cub_data *cb_data, float player_x, float player_y,
		int colomn)
{
	float	delta_x;
	float	delta_y;

	if (sin(cb_data->ray_angle) > 0)
		cb_data->sr[colomn].hy_inter = (int)(player_y / CELL_SIZE) 
			*CELL_SIZE + CELL_SIZE;
	else
		cb_data->sr[colomn].hy_inter = (int)(player_y / CELL_SIZE) *CELL_SIZE;
	cb_data->sr[colomn].hx_inter = player_x + ((cb_data->sr[colomn].hy_inter
				- player_y) / tan(cb_data->ray_angle));
	delta_y = CELL_SIZE;
	if (sin(cb_data->ray_angle) < 0)
		delta_y *= -1;
	delta_x = delta_y / tan(cb_data->ray_angle);
	check_horizontal(cb_data, delta_x, delta_y, colomn);
}

void	cast_vertical(t_cub_data *cb_data, float player_x, float player_y,
		int colomn)
{
	float	delta_x;
	float	delta_y;

	if (cos(cb_data->ray_angle) > 0)
		cb_data->sr[colomn].vx_inter = (int)(player_x / CELL_SIZE) *CELL_SIZE
			+ CELL_SIZE;
	else
		cb_data->sr[colomn].vx_inter = (int)(player_x / CELL_SIZE) *CELL_SIZE;
	cb_data->sr[colomn].vy_inter = player_y + ((cb_data->sr[colomn].vx_inter
				- player_x) * tan(cb_data->ray_angle));
	delta_x = CELL_SIZE;
	if (cos(cb_data->ray_angle) < 0)
		delta_x *= -1;
	delta_y = delta_x * tan(cb_data->ray_angle);
	check_vertical(cb_data, delta_x, delta_y, colomn);
}

void	compare_distance(t_cub_data *cb_data, float player_x, float player_y,
		int colomn)
{
	cb_data->sr[colomn].hor_dist = sqrt(pow((player_x
					- cb_data->sr[colomn].hx_inter), 2)
			+ pow((player_y - cb_data->sr[colomn].hy_inter), 2));
	cb_data->sr[colomn].ver_dist = sqrt(pow((player_x
					- cb_data->sr[colomn].vx_inter), 2) + pow((player_y
					- cb_data->sr[colomn].vy_inter), 2));
	if (cb_data->sr[colomn].hor_dist < cb_data->sr[colomn].ver_dist)
	{
		cb_data->sr[colomn].r_distance = cb_data->sr[colomn].hor_dist;
		cb_data->sr[colomn].hit_side = 0;
	}
	else
	{
		cb_data->sr[colomn].r_distance = cb_data->sr[colomn].ver_dist;
		cb_data->sr[colomn].hit_side = 1;
	}
}

void	ray_cast(mlx_image_t *player, t_cub_data *cb_data, float player_x,
		float player_y)
{
	int		colomn;

	(void)player;
	colomn = 0;
	cb_data->ray_angle = cb_data->c_player.rotation_angle - (FOV / 2);
	if (cb_data->sr)
		free(cb_data->sr);
	cb_data->sr = malloc((NUM_RAYS + 1) * sizeof(t_ray));
	cb_data->sr->hit_side = 0;
	while (colomn < NUM_RAYS)
	{
		normalize_angle(cb_data);
		cb_data->sr[colomn].ray_angle = cb_data->ray_angle;
		cb_data->sr[colomn].player_rotation_angle
			= cb_data->c_player.rotation_angle;
		cast_horizontal(cb_data, player_x, player_y, colomn);
		cast_vertical(cb_data, player_x, player_y, colomn);
		cb_data->sr[colomn].x = player_x;
		cb_data->sr[colomn].y = player_y;
		compare_distance(cb_data, player_x, player_y, colomn);
		cb_data->ray_angle += (FOV / NUM_RAYS);
		colomn++;
	}
	drawing_walls(cb_data);
}
