/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:57:39 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/21 14:34:48 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"





void draw_map_rays(t_cub_data *cb_data)
{
	int index = 0; 
	while (index < NUM_RAYS)
    {
        if(cb_data->sr[index].hor_dist <= cb_data->sr[index].ver_dist)
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
    float corr_dist;
    float alpha;
    float start;
    float offset_x;
    float offset_y;
    
    alpha = cb_data->sr[index].ray_angle -cb_data->sr[index].player_rotation_angle;
    corr_dist = cb_data->sr[index].r_distance * cos(alpha) / CELL_SIZE;
    Projected_Wall_Height = (HEIGHT / corr_dist);
    start = HEIGHT / 2 - Projected_Wall_Height / 2;
    if(start < 0)
        start = 0;
   
    offset_y = 0;
    offset_x = 0;
    printf("%f\n", cb_data->sr[index].hit_side);
    if(cb_data->sr[index].hit_side == 0)
        offset_x = (int)(cb_data->sr[index].hx_inter * cb_data->t_wall->width / CELL_SIZE) % cb_data->t_wall->width;
    else if(cb_data->sr[index].hit_side == 1)
        offset_x = (int)(cb_data->sr[index].vy_inter * cb_data->t_wall->width / CELL_SIZE) % cb_data->t_wall->width;

    
    float e;
    float step = cb_data->t_wall->height / Projected_Wall_Height;

    e = Projected_Wall_Height / 2 - HEIGHT / 2;
    if(e  < 0)
        e  = 0;

    y = 0;
    offset_y = step * e;

    while(y < (int)Projected_Wall_Height && y < HEIGHT)
    {
        mlx_put_pixel(cb_data->map_img, index, start + y,  cb_data->wall_texture[((int)offset_y * cb_data->t_wall->width) + (int)offset_x]);
        offset_y +=step;

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