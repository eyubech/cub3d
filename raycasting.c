/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:06:23 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/20 11:42:01 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_cast(mlx_image_t *player, t_cub_data *cb_data, float player_x, float player_y)
{
	float hx_inter;
	float hy_inter;
	float vx_inter;
	float vy_inter;
	
	float delta_x;
	float delta_y;
	
	float theta;
	int colomn;
	colomn = 0;
	theta = FOV / 2;

	float hor_dist;
	float ver_dist;

	
	cb_data->ray_angle  = cb_data->c_player.rotation_angle - theta;
	cb_data->sr = malloc((NUM_RAYS + 1) * sizeof(t_ray));
	
	cb_data->sr->hit_side = 0;
	while(colomn < NUM_RAYS)
	{
		
		if(cb_data->ray_angle <= 0)
			cb_data->ray_angle += 2 * M_PI;
			
		else if(cb_data->ray_angle > 2 * M_PI)
			cb_data->ray_angle -= 2 * M_PI;
		

		
		cb_data->sr[colomn].ray_angle = cb_data->ray_angle;
		cb_data->sr[colomn].player_rotation_angle = cb_data->c_player.rotation_angle;
		
		
		
		//check for horizontal intersections:
		if(sin(cb_data->ray_angle) > 0)
			cb_data->sr[colomn].hy_inter = (int)(player_y / CELL_SIZE) * CELL_SIZE + CELL_SIZE;
		else
			cb_data->sr[colomn].hy_inter = (int)(player_y / CELL_SIZE) * CELL_SIZE;
		cb_data->sr[colomn].hx_inter = player_x + ((cb_data->sr[colomn].hy_inter - player_y) / tan(cb_data->ray_angle));
		delta_y = CELL_SIZE;
		if(sin(cb_data->ray_angle) < 0)
			delta_y *= -1;
		delta_x = delta_y / tan(cb_data->ray_angle);
		
		
		int check_h = 0;
		while(cb_data->sr[colomn].hx_inter >= 0 && cb_data->sr[colomn].hx_inter < MAP_WIDTH && cb_data->sr[colomn].hy_inter >= 0 && cb_data->sr[colomn].hy_inter < MAP_HEIGHT)
		{
			if(sin(cb_data->ray_angle) <= 0)
				check_h = cb_data->sr[colomn].hy_inter - 1;
			else
				check_h = cb_data->sr[colomn].hy_inter;
			if(is_wall(check_h, cb_data->sr[colomn].hx_inter, cb_data) == 1)
			{
				cb_data->sr[colomn].hit_side = 0;
				break;
			}
			else
			{
				cb_data->sr[colomn].hy_inter += delta_y;
				cb_data->sr[colomn].hx_inter += delta_x;
			}
		}

		
		//check for vertical interesections 
		
		if(cos(cb_data->ray_angle) > 0)
			cb_data->sr[colomn].vx_inter = (int)(player_x / CELL_SIZE) * CELL_SIZE + CELL_SIZE;
		else
			cb_data->sr[colomn].vx_inter = (int)(player_x / CELL_SIZE) * CELL_SIZE;
		cb_data->sr[colomn].vy_inter = player_y + ((cb_data->sr[colomn].vx_inter - player_x) * tan(cb_data->ray_angle));
		delta_x = CELL_SIZE;
		if(cos(cb_data->ray_angle) < 0)
			delta_x *= -1;
		delta_y = delta_x * tan(cb_data->ray_angle);
		
		


		
		int check_v = 0;
		while(cb_data->sr[colomn].vx_inter >= 0 && cb_data->sr[colomn].vx_inter < MAP_WIDTH && cb_data->sr[colomn].vy_inter >= 0 && cb_data->sr[colomn].vy_inter < MAP_HEIGHT)
		{
			if(cos(cb_data->ray_angle) <= 0)
				check_v = cb_data->sr[colomn].vx_inter - 1;
			else
				check_v = cb_data->sr[colomn].vx_inter;
			if(is_wall(cb_data->sr[colomn].vy_inter, check_v, cb_data) == 1)
			{
				cb_data->sr[colomn].hit_side = 1;
				break;
			}
			else
			{
				cb_data->sr[colomn].vy_inter += delta_y;
				cb_data->sr[colomn].vx_inter += delta_x;
			}
		}
		
		cb_data->sr[colomn].x = player_x;
		cb_data->sr[colomn].y = player_y;
		
		//calcul the distance and choose the short distance 
		cb_data->sr[colomn].hor_dist = sqrt(pow((player_x - cb_data->sr[colomn].hx_inter), 2) + pow((player_y - cb_data->sr[colomn].hy_inter), 2));
		cb_data->sr[colomn].ver_dist = sqrt(pow((player_x - cb_data->sr[colomn].vx_inter), 2) + pow((player_y - cb_data->sr[colomn].vy_inter), 2));

		  // draw_map(cb_data);
		if(cb_data->sr[colomn].hor_dist < cb_data->sr[colomn].ver_dist)
		{
			cb_data->sr[colomn].r_distance = cb_data->sr[colomn].hor_dist;
			// draw_line(player_x, player_y, cb_data->sr[colomn].hx_inter, cb_data->sr[colomn].hy_inter, cb_data->map_img);
		}
		else
		{
			cb_data->sr[colomn].r_distance = cb_data->sr[colomn].ver_dist;
			// draw_line(player_x, player_y, cb_data->sr[colomn].vx_inter, cb_data->sr[colomn].vy_inter, cb_data->map_img);
		}

		cb_data->ray_angle += (FOV / NUM_RAYS);
		colomn++;
	}
	drawing_walls(cb_data);
	
}

