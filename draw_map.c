/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:50:42 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/15 14:30:45 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"





void draw_background(mlx_image_t* background)
{
    int x=0;
    int y=0;
    
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT / 2)
        {
            mlx_put_pixel(background, x, y, 0x6F2DA8FF);
            y += 1;
        }
        x += 1;
    }
    x = 0;
    while (x < WIDTH)
    {
        y = HEIGHT / 2;
        while (y < HEIGHT)
        {
            mlx_put_pixel(background, x, y, 0x808080FF);
            y += 1;
        }
        x += 1;
    }
}





void draw_line_ver(mlx_image_t* lines)
{
    int x=0;
    int y=0;

    while (x < MAP_WIDTH)
    {
        y = 0;
        while (y < MAP_HEIGHT)
        {
            mlx_put_pixel(lines, x, y, 0x808080FF);
            y += 1;
        }
        x += CELL_SIZE;
    }
    
}

void draw_line_hor(mlx_image_t* lines)
{
    int x=0;
    int y=0;

    while (y < MAP_HEIGHT)
    {
        x = 0;
        while (x < MAP_WIDTH)
        {
            mlx_put_pixel(lines, x, y, 0x808080FF);
            x += 1;
        }
        

        y += CELL_SIZE;
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

void draw_curs(int x0, int y0, int x1, int y1,mlx_image_t* map) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1) 
    {
        mlx_put_pixel(map,x0, y0, 0xFF0000FF);
        
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
	int i = x + CELL_SIZE;
	int j = y + CELL_SIZE;
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
	int i = player_x + PLAYER_SIZE;
	int j = player_y + PLAYER_SIZE;
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
    ray_cast(player, cb_data, player_x, player_y); 
    // draw_curs(player_x , player_y , player_x + cos(cb_data->c_player.rotation_angle) * 50, player_y + sin(cb_data->c_player.rotation_angle)*50,player);
}




void draw_map(t_cub_data *cb_data)
{
    int i;
    int j;
    int x;
    int y;


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
            j += 1;
            x += CELL_SIZE;
        }
        y += CELL_SIZE;
        i += 1;
    }
    draw_line_ver(cb_data->map_img);
    draw_line_hor(cb_data->map_img);
}