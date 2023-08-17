/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:57:39 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/17 18:10:46 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"





void draw_map_rays(t_cub_data *cb_data)
{
	int index = 0; 
	while (index < NUM_RAYS)
    {
        if(cb_data->sr[index].hor_dist < cb_data->sr[index].ver_dist)
			draw_line(cb_data->sr[index].x, cb_data->sr[index].y, cb_data->sr[index].hx_inter, cb_data->sr[index].hy_inter, cb_data->map_img);
		else
			draw_line(cb_data->sr[index].x, cb_data->sr[index].y, cb_data->sr[index].vx_inter, cb_data->sr[index].vy_inter, cb_data->map_img);
        index += 1;
    }
    
}








void draw_wall(t_cub_data *cb_data, int index)
{

    int y;
    float Projected_Wall_Height;
    float Dis_From_Proplane;
    float corr_dist;
    float alpha;
    float start;

    alpha = cb_data->sr[index].ray_angle -cb_data->sr[index].player_rotation_angle;
    corr_dist = cb_data->sr[index].r_distance * cos(alpha);
    Dis_From_Proplane = (WIDTH / 2) / tan(FOV / 2);
    Projected_Wall_Height = (CELL_SIZE / corr_dist) * Dis_From_Proplane;
    start = HEIGHT / 2 - Projected_Wall_Height / 2;
    if(start < 0)
        start = 0;
    y = 0;
    while(y < Projected_Wall_Height && y < HEIGHT)
    {
        mlx_put_pixel(cb_data->map_img, index, start + y, 0xFFFFFF);
        y++;
    }
}


void drawing_walls(t_cub_data *cb_data)
{
	int index;

	index = 0;

	while (index < NUM_RAYS)
	{
		draw_wall(cb_data, index);
		index += 1;
	}
	
}