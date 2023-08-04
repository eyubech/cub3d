/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:06:23 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/04 17:37:10 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_cast(t_cub_data *cb_data, int player_x, int player_y)
{
	float ray_angle;
	float theta;
	int colomn;
	colomn = 0;
	theta = FOV / 2;
	ray_angle  = cb_data->rotation_angle - theta;
	// printf("%f\n", cb_data->player_y);
	while(colomn < NUM_RAYS)
	{
    	draw_line(player_x - 8, player_y - 8, player_x+ cos(ray_angle) * 80, player_y + sin(ray_angle) * 80 , cb_data->map_img);
		//cast a ray
		//Trace the ray until it intersects with a wall (map[i][j] == 1)
		//record the intersection (x, y) and the distance (ray length)
		ray_angle += (FOV / NUM_RAYS);
		colomn++;
	}
}