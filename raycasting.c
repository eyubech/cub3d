/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:06:23 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/13 16:02:17 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_cast(t_cub_data *cb_data, int player_x, int player_y)
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

	
	cb_data->ray.ray_angle  = cb_data->c_player.rotation_angle - theta;
	// printf("%f\n", cb_data->ray.ray_angle);
	// printf("%f\n", FOV);

	// printf("x:%d y:%d\n", player_x, player_y);
	// exit(0);
	
	while(colomn < NUM_RAYS)
	{
		
			if(cb_data->ray.ray_angle <= 0)
				cb_data->ray.ray_angle += 2 * M_PI;
				
			else if(cb_data->ray.ray_angle > 2 * M_PI)
				cb_data->ray.ray_angle -= 2 * M_PI;
			
			//check for horizontal intersections:	
			if(sin(cb_data->ray.ray_angle) > 0)
				hy_inter = (int)(player_y / CELL_SIZE) * CELL_SIZE + CELL_SIZE;
			else
				hy_inter = (int)(player_y / CELL_SIZE) * CELL_SIZE;
			hx_inter = player_x + ((hy_inter - player_y) / tan(cb_data->ray.ray_angle));
			printf("angle:%f\n", cb_data->ray.ray_angle);
			
			// printf("tangent:%f\n", tan(cb_data->ray.ray_angle));
			printf("----->:%f\n", (hy_inter - player_y) / tan(cb_data->ray.ray_angle));
			printf("hx:%f hy:%f\n", hx_inter, hy_inter);
			printf("px:%d py:%d\n", player_x, player_y);
			
			delta_y = CELL_SIZE;
			if(sin(cb_data->ray.ray_angle) < 0)
				delta_y *= -1;
			delta_x = delta_y / tan(cb_data->ray.ray_angle);
			
			
			int check_h = 0;
			while(hx_inter >= 0 && hx_inter < WIDTH && hy_inter >= 0 && hy_inter < HEIGHT)
			{
				if(sin(cb_data->ray.ray_angle) <= 0)
					check_h = hy_inter - 1;
				else
					check_h = hy_inter;
				if(is_wall(check_h, hx_inter, cb_data) == 1)
				{
					// draw_line(player_x - 8, player_y - 8, hx_inter, hy_inter, cb_data->map_img);
					break;
				}
				else
				{
					hy_inter += delta_y;
					hx_inter += delta_x;
				}
			}

			//check for vertical interesections 
				
			if(cos(cb_data->ray.ray_angle) > 0)
				vx_inter = (int)(player_x / CELL_SIZE) * CELL_SIZE + CELL_SIZE;
			else
				vx_inter = (int)(player_x / CELL_SIZE) * CELL_SIZE;
			vy_inter = player_y + ((vx_inter - player_x) * tan(cb_data->ray.ray_angle));
			delta_x = CELL_SIZE;
			if(cos(cb_data->ray.ray_angle) < 0)
				delta_x *= -1;
			delta_y = delta_x * tan(cb_data->ray.ray_angle);
			
			
			int check_v = 0;
			while(vx_inter >= 0 && vx_inter < WIDTH && vy_inter >= 0 && vy_inter < HEIGHT)
			{
				if(cos(cb_data->ray.ray_angle) <= 0)
					check_v = vx_inter - 1;
				else
					check_v = vx_inter;
				if(is_wall(vy_inter, check_v, cb_data) == 1)
				{
					// draw_line(player_x - 8, player_y - 8, vx_inter, vy_inter, cb_data->map_img);
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
				draw_line(player_x, player_y, hx_inter, hy_inter, cb_data->map_img);
			}
			else
			{
				draw_line(player_x, player_y, vx_inter, vy_inter, cb_data->map_img);
			}
    	// draw_line(player_x - 8, player_y - 8, player_x+ cos(cb_data->ray.ray_angle) * 80, player_y + sin(cb_data->ray.ray_angle) * 80 , cb_data->map_img);
		cb_data->ray.ray_angle += (FOV / NUM_RAYS);
		colomn++;
	}
}

