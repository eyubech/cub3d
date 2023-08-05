/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:50:42 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/05 11:34:05 by nel-mous         ###   ########.fr       */
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
void draw_line(int x0, int y0, int x1, int y1,mlx_image_t* map) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1) 
    {
        mlx_put_pixel(map,x0, y0, 0x008000FF);

        if (x0 == x1 && y0 == y1)
            break;

        e2 = err;

        if (e2 > -dx) 
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dy) 
        {
            err += dx;
            y0 += sy;
        }
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
    (void)cb_data;
    cb_data->c_player.end_x = cb_data->c_player.px_dir + player_x;
    cb_data->c_player.end_y = cb_data->c_player.py_dir + player_y;
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

    // draw_line(player_x -8, player_y-8, player_x + cos(cb_data->rotation_angle) * 50, player_y + sin(cb_data->rotation_angle)*50,player);
    ray_cast(cb_data, player_x, player_y);
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