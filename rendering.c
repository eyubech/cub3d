/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:57:39 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/20 11:47:39 by nel-mous         ###   ########.fr       */
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






// void draw_wall(t_cub_data *cb_data, int index)
// {

//     if(index < 600){
//         int y;
//     float Projected_Wall_Height;
//     float Dis_From_Proplane;
//     float corr_dist;
//     float alpha;
//     float start;
//     int offset_x;
//     int offset_y;
    
//     alpha = cb_data->sr[index].ray_angle -cb_data->sr[index].player_rotation_angle;
//     corr_dist = cb_data->sr[index].r_distance * cos(alpha);
//     Dis_From_Proplane = (WIDTH / 2) / tan(FOV / 2);
//     Projected_Wall_Height = (CELL_SIZE / corr_dist) * Dis_From_Proplane;
//     start = HEIGHT / 2 - Projected_Wall_Height / 2;
//     if(start < 0)
//         start = 0;
   
//     offset_y = 0;
//     if(cb_data->sr[index].hit_side == 0)
//     {
//         offset_x = (cb_data->t_wall->width / CELL_SIZE) * (cb_data->sr[index].hx_inter - ((int)(cb_data->sr[index].hx_inter / 50) * 50));
//         // offset_x = (cb_data->t_wall->width / CELL_SIZE) * ((int)cb_data->sr[index].hx_inter % CELL_SIZE);
//         // offset_x =  (int)cb_data->sr[index].hx_inter % cb_data->t_wall->width;
//     }
//     else if(cb_data->sr[index].hit_side == 1)
//     {
//         offset_x = (cb_data->t_wall->width / CELL_SIZE) * (cb_data->sr[index].vy_inter - ((int)(cb_data->sr[index].vy_inter / 50) * 50));
//         // offset_x = (cb_data->t_wall->width / CELL_SIZE) * ((int)cb_data->sr[index].vy_inter % CELL_SIZE);
//         // offset_x =  (int)cb_data->sr[index].vy_inter % cb_data->t_wall->width;
//     }
//     y = 0;
//     // printf("offset_x:%d\n", offset_x);
//     offset_y = Projected_Wall_Height / 2 - HEIGHT / 2;
//     if(offset_y  < 0)
//         offset_y  = 0;
//     offset_y *= cb_data->t_wall->height / Projected_Wall_Height;
//     while(y < Projected_Wall_Height && y < HEIGHT)
//     {
        
//         mlx_put_pixel(cb_data->map_img, index, start + y,  cb_data->wall_texture[(((offset_y) * cb_data->t_wall->width) + offset_x)]);
//         offset_y +=(cb_data->t_wall->height / Projected_Wall_Height);
//         // mlx_put_pixel(cb_data->map_img, index, start + y,  cb_data->wall_texture[ y * cb_data->t_wall->width + index]);
//         y++;
//     }
//     }
// }

void draw_wall(t_cub_data *cb_data, int index)
{

    float y;
    float Projected_Wall_Height;
    float Dis_From_Proplane;
    float corr_dist;
    float alpha;
    float start;

    alpha = cb_data->sr[index].ray_angle - cb_data->sr[index].player_rotation_angle;
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