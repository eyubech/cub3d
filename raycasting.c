/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:06:23 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/07 14:39:47 by nel-mous         ###   ########.fr       */
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
	
	float next_hx_inter;
	float next_hy_inter;
	float next_vx_inter;
	float next_vy_inter;
	
	float inter_wall_hx;
	float inter_wall_hy;
	float inter_wall_vx;
	float inter_wall_vy;

	float h_dist;
	float v_dist;

	float distance;
	
	float theta;
	int colomn;
	colomn = 0;
	theta = FOV / 2;
	cb_data->ray.ray_angle  = cb_data->c_player.rotation_angle - theta;
	cb_data->ray.wall_coor = 0;
	// printf("%f\n", cb_data->player_y);
	while(colomn < NUM_RAYS)
	{
		//check for horizontal intersections:
			//1-find coordinate of the first horizontal intersection
			if(cb_data->ray.ray_angle < 0 && cb_data->ray.ray_angle > M_PI) //facing up
			{
				hy_inter = (int)(cb_data->c_player.player_y / CELL_SIZE) * CELL_SIZE;
			}
			else if (cb_data->ray.ray_angle > 0 && cb_data->ray.ray_angle < M_PI) //facing down
			{
				hy_inter = (int)(cb_data->c_player.player_y / CELL_SIZE) * CELL_SIZE + CELL_SIZE;
			}
			hx_inter = cb_data->c_player.player_x + ((cb_data->c_player.player_y - hy_inter) / tan(cb_data->ray.ray_angle));
			
			//2-find y_step(delta_y)
			delta_y = CELL_SIZE;
			if(cb_data->ray.ray_angle < 0 && cb_data->ray.ray_angle > M_PI) //facing up 
				delta_y *= -1;
			//3-find x_step(delta_x)
			delta_x = CELL_SIZE / tan(cb_data->ray.ray_angle);
			if((cb_data->ray.ray_angle > M_PI / 2 && cb_data->ray.ray_angle < M_PI) || (cb_data->ray.ray_angle > M_PI && cb_data->ray.ray_angle < 3 * M_PI / 2))
				delta_x *= -1;
			//4-convert intersection point(x,y) into map index[i,j]
			//5-if(intersection hits a wall):
				//then:store horizontal hit distance
				//else: find next horizontal intersection (by incrementing x_step and y_step)
			next_hy_inter = hy_inter;
			next_hx_inter = hx_inter;
			while(next_hx_inter > 0 && next_hx_inter < WIDTH && next_hy_inter > 0 && next_hy_inter < HEIGHT)
			{
				if(is_wall(next_hx_inter, next_hy_inter, cb_data) == 1)
				{
					cb_data->ray.wall_coor = 1;
					inter_wall_hx = next_hx_inter;
					inter_wall_hy = next_hy_inter;
					draw_line(player_x - 8, player_y - 8, inter_wall_hx, inter_wall_hy, cb_data->map_img);
					break;
				}
				else
				{
					next_hy_inter += delta_y;
					next_hx_inter += delta_x;
				}
			}
			
		// check for vertical intersections:
			// 1-find coordinate of the first vertical intersection
			if(cb_data->ray.ray_angle < M_PI / 2 || cb_data->ray.ray_angle > (3 * M_PI / 2)) //facing_right
				vx_inter = (int)(cb_data->c_player.player_x / CELL_SIZE) * CELL_SIZE;
			else // facing left
				vx_inter = (int)(cb_data->c_player.player_x / CELL_SIZE) * CELL_SIZE + CELL_SIZE;
			vy_inter = cb_data->c_player.player_y + ((cb_data->c_player.player_x - vx_inter) * tan(cb_data->ray.ray_angle));
			//2-find x_step(delta_x)
			delta_x = CELL_SIZE; // facing left
			if(cb_data->ray.ray_angle < M_PI / 2 && cb_data->ray.ray_angle > (3 * M_PI / 2)) // facing right
				delta_x *= -1;
			//3-find y_step(delta_y)
			delta_y = CELL_SIZE / tan(cb_data->ray.ray_angle);
			// if()
			// {
			// 	delta_y *= -1
			// }
			//4-convert intersection point(x,y) into map index[i,j]
			//5-if(intersection hits a wall):
				//then:store vertical hit distance
				//else: find next vertical intersection (by incrementing x_step and y_step)
			next_vy_inter = vy_inter;
			next_vx_inter = vx_inter;
			while(next_vx_inter > 0 && next_vx_inter < HEIGHT && next_vy_inter > 0 && next_vy_inter < WIDTH)
			{
				if(is_wall(next_vx_inter, next_vy_inter, cb_data) == 1)
				{
					cb_data->ray.wall_coor = 1;
					inter_wall_vx = next_vx_inter;
					inter_wall_vy = next_vy_inter;
					// draw_line(player_x - 8, player_y - 8, inter_wall_vx, inter_wall_vy, cb_data->map_img);
					break;
				}
				else
				{
					next_vy_inter += delta_y;
					next_vx_inter += delta_x;
				}
			}
		// distance from ray to wall hit :
			if(cb_data->ray.wall_coor == 1)
			{
				h_dist = sqrt(pow((cb_data->c_player.player_x - inter_wall_hx), 2) + pow((cb_data->c_player.player_y - inter_wall_hy), 2));
				v_dist = sqrt(pow((cb_data->c_player.player_x - inter_wall_vx), 2) + pow((cb_data->c_player.player_y - inter_wall_vy), 2));
			}
			if(h_dist < v_dist)
			{
				distance = h_dist;
				draw_line(player_x - 8, player_y - 8, inter_wall_hx, distance, cb_data->map_img);
			}
			else
			{
				distance = v_dist;
				draw_line(player_x - 8, player_y - 8, inter_wall_vx, distance, cb_data->map_img);
			}
			// the closest one 
		
    	// draw_line(player_x - 8, player_y - 8, player_x+ cos(cb_data->ray.ray_angle) * 80, player_y + sin(cb_data->ray.ray_angle) * 80 , cb_data->map_img);
		cb_data->ray.ray_angle += (FOV / NUM_RAYS);
		colomn++;
	}
}
