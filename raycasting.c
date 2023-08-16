/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:06:23 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/15 21:41:59 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_cast(mlx_image_t *player, t_cub_data *cb_data, int player_x, int player_y)
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
	while(colomn < NUM_RAYS)
	{
		
			if(cb_data->ray_angle <= 0)
				cb_data->ray_angle += 2 * M_PI;
				
			else if(cb_data->ray_angle > 2 * M_PI)
				cb_data->ray_angle -= 2 * M_PI;
			
			//check for horizontal intersections:	
			if(sin(cb_data->ray_angle) > 0)
				hy_inter = (int)(player_y / CELL_SIZE) * CELL_SIZE + CELL_SIZE;
			else
				hy_inter = (int)(player_y / CELL_SIZE) * CELL_SIZE;
			hx_inter = player_x + ((hy_inter - player_y) / tan(cb_data->ray_angle));
			delta_y = CELL_SIZE;
			if(sin(cb_data->ray_angle) < 0)
				delta_y *= -1;
			delta_x = delta_y / tan(cb_data->ray_angle);
			
			
			int check_h = 0;
			while(hx_inter >= 0 && hx_inter < MAP_WIDTH && hy_inter >= 0 && hy_inter < MAP_HEIGHT)
			{
				if(sin(cb_data->ray_angle) <= 0)
					check_h = hy_inter - 1;
				else
					check_h = hy_inter;
				if(is_wall(check_h, hx_inter, cb_data) == 1)
				{
					
					break;
				}
				else
				{
					hy_inter += delta_y;
					hx_inter += delta_x;
				}
			}

			//check for vertical interesections 
			
			if(cos(cb_data->ray_angle) > 0)
				vx_inter = (int)(player_x / CELL_SIZE) * CELL_SIZE + CELL_SIZE;
			else
				vx_inter = (int)(player_x / CELL_SIZE) * CELL_SIZE;
			vy_inter = player_y + ((vx_inter - player_x) * tan(cb_data->ray_angle));
			delta_x = CELL_SIZE;
			if(cos(cb_data->ray_angle) < 0)
				delta_x *= -1;
			delta_y = delta_x * tan(cb_data->ray_angle);
			
			
			int check_v = 0;
			while(vx_inter >= 0 && vx_inter < MAP_WIDTH && vy_inter >= 0 && vy_inter < MAP_HEIGHT)
			{
				if(cos(cb_data->ray_angle) <= 0)
					check_v = vx_inter - 1;
				else
					check_v = vx_inter;
				if(is_wall(vy_inter, check_v, cb_data) == 1)
				{
					
					break;
				}
				else
				{
					vy_inter += delta_y;
					vx_inter += delta_x;
				}
			}
			
			//calcul the distance and choose the short distance 
			hor_dist = sqrt(pow((player_x - hx_inter), 2) + pow((player_y - hy_inter), 2));
			ver_dist = sqrt(pow((player_x - vx_inter), 2) + pow((player_y - vy_inter), 2));
			if(hor_dist < ver_dist)
			{
				cb_data->ray.r_distance = hor_dist;
				draw_line(player_x, player_y, hx_inter, hy_inter, cb_data->map_img);
			}
			else
			{
				cb_data->ray.r_distance = ver_dist;
				draw_line(player_x, player_y, vx_inter, vy_inter, cb_data->map_img);
			}
			drawing_walls(player, cb_data, colomn);
		cb_data->ray_angle += (FOV / NUM_RAYS);
		colomn++;
	}
}

