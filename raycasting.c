/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:06:23 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/05 15:13:56 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int is_wall(float x, float y, t_cub_data *cb_data)
{
	int map_x;
	int map_y;
	map_x = (int)(x/CELL_SIZE);
	map_y = (int)(y/CELL_SIZE);
	if(cb_data->map[map_x][map_y] != 0)
		return(1);
	return(0);	
}
void	ray_cast(t_cub_data *cb_data, int player_x, int player_y)
{
	float hx_inter;
	float hy_inter;
	float theta;
	int colomn;
	colomn = 0;
	theta = FOV / 2;
	cb_data->ray.ray_angle  = cb_data->c_player.rotation_angle - theta;
	// printf("%f\n", cb_data->player_y);
	while(colomn < NUM_RAYS)
	{
		//check for horizontal intersections:
			//1-find coordinate of the first horizontal intersection
			//2-find y_step(delta_y)
			//3-find x_step(delta_x)
			//4-convert intersection point(x,y) into map index[i,j]
			//5-if(intersection hits a wall):
				//then:store horizontal hit distance
				//else: find next horizontal intersection (by incrementing x_step and y_step)
			
		//check for vertical intersections:
			//1-find coordinate of the first vertical intersection
			//2-find x_step(delta_y)
			//3-find y_step(delta_x)
			//4-convert intersection point(x,y) into map index[i,j]
			//5-if(intersection hits a wall):
				//then:store vertical hit distance
				//else: find next vertical intersection (by incrementing x_step and y_step)
		//distance from ray to wall hit :
			//the closest one 
		
    	draw_line(player_x - 8, player_y - 8, player_x+ cos(cb_data->ray.ray_angle) * 80, player_y + sin(cb_data->ray.ray_angle) * 80 , cb_data->map_img);
		cb_data->ray.ray_angle += (FOV / NUM_RAYS);
		colomn++;
	}
}