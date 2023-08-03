/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:50:42 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/03 11:22:26 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"




void draw_line_ver(mlx_image_t* lines)
{
    int x=0;
    int y=0;

    while (x <= 550)
    {
        y = 0;
        while (y <= 350)
        {
            mlx_put_pixel(lines, x, y, 0x808080FF);
            y += 1;
        }
        x += 50;
    }
    
}

void draw_line_hor(mlx_image_t* lines)
{
    int x=0;
    int y=0;

    while (y <= 350)
    {
        x = 0;
        while (x <= 550)
        {
            mlx_put_pixel(lines, x, y, 0x808080FF);
            x += 1;
        }
        

        y += 50;
    }
    
}

void ft_dda(mlx_image_t* map, int p1_x, int p1_y, int p2_x, int p2_y)
{
	int i = 0;
	float dx = fabs((float)p1_x - (float)p2_x);
	float dy = fabs((float)p1_y - (float)p2_y);
	float max = fmax(dx , dy);
	float step_x = dx / max; // 1
	float step_y = dy / max; // 0.5
	float x = p1_x ;
	float y = p1_y;
	while (i < max)
	{
        mlx_put_pixel(map, x, y, 0xFF0000);
		// my_mlx_pixel_put(&mlx->img, x, y, 0x000000);	
		x += step_x;
		y += step_y;
		i++;
	}
}

void draw_box(mlx_image_t* map, int x, int y, uint32_t color)
{
	int i = x + 50;
	int j = y + 50;
    int save_x = x;
	
	while (y < j)
	{
		x = save_x;
		while (x < i)
        {
			mlx_put_pixel(map, x, y, color);
            x += 1;
        }
		y += 1;
	}
}

void draw_player(mlx_image_t* player, int player_x, int player_y, t_cub_data *cb_data)
{
	int i = player_x + 16;
	int j = player_y + 16;
    cb_data->end_x = player_x + 10;
    cb_data->end_y = player_y + 10;
    // int x = player_x + 8;
    // int y = player_y + 8;
    float save_x = player_x;
	
	while (player_y < j)
	{
		player_x = save_x;
		while (player_x < i)
        {
			mlx_put_pixel(player, player_x, player_y, 0xFF0000FF);
            player_x += 1;
        }
		player_y += 1;
	}
    ft_dda(player, player_x, player_y, cb_data->end_x, cb_data->end_y);
    // i = 25;
    // while (i--)
    //     mlx_put_pixel(player, x, y--, 0xFF0000FF);
}




void draw_map(t_cub_data *cb_data, mlx_t* mlx)
{
    int i;
    int j;
    int x;
    int y;

    (void)mlx;
    i = 0;
    
    y = 0;
    while (cb_data->map[i])
    {
        j = 0;
        x = 0;
        while (cb_data->map[i][j])
        {
            if (cb_data->map[i][j] == '1')
                draw_box(cb_data->map_img, x, y, 0x0000FFFF);
            else
                draw_box(cb_data->map_img, x, y, 0xFFFFFFFF);
            // if (cb_data->map[i][j] == 'P')
            // {
            //     // cb_data->player_x = x;
            //     // cb_data->player_y = y;
                
            // }
            j += 1;
            x += 50;
        }
        y += 50;
        i += 1;
    }
    draw_line_ver(cb_data->map_img);
    draw_line_hor(cb_data->map_img);
}