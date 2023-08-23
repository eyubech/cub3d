/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:50:42 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/23 17:12:11 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"





void draw_background(t_cub_data *cb_data)
{
    int x=0;
    int y=0;
    
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT / 2)
        {
            mlx_put_pixel(cb_data->map_img, x, y, 0x6F2DA8FF );
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
            mlx_put_pixel(cb_data->map_img, x, y, 0x808080FF );
            y += 1;
        }
        x += 1;
    }
}





void draw_line_ver(t_cub_data *cb_data)
{
    int x=0;
    int y=0;

    while (x < MAP_WIDTH)
    {
        y = 0;
        while (y < MAP_HEIGHT)
        {
            mlx_put_pixel(cb_data->map_img, x, y, 0x808080FF );
            y += 1;
        }
        x += CELL_SIZE;
    }
    
}

void draw_line_hor(t_cub_data *cb_data)
{
    int x=0;
    int y=0;

    while (y < MAP_HEIGHT)
    {
        x = 0;
        while (x < MAP_WIDTH)
        {
            mlx_put_pixel(cb_data->map_img, x, y, 0x808080FF );
            x += 1;
        }
        

        y += CELL_SIZE;
    }
    
}
void draw_line(float x0, float y0, float x1, float y1, t_cub_data *cb_data) 
{
    float dx;
    float dy;
    int step;
    float x_inc;
    float y_inc;
    int i;
    dx = x1 - x0;
    dy = y1 - y0;
    step = fabs(dx) + fabs(dy);
    x_inc = dx/step;
    y_inc = dy/step;
    i = 0;
    while(i < step)
    {
        mlx_put_pixel(cb_data->map_img,x0, y0, 0x008000FF );
        x0 = x0 + x_inc;
        y0 = y0 + y_inc;
        i++;
    }
}


void draw_curs(float x0, float y0, float x1, float y1, t_cub_data *cb_data) 
{
    float dx;
    float dy;
    int step;
    float x_inc;
    float y_inc;
    int i;
    dx = x1 - x0;
    dy = y1 - y0;
    if(fabs(dx) > fabs(dy))
        step = fabs(dx);
    else
        step = fabs(dy);
    x_inc = dx/step;
    y_inc = dy/step;
    i = 1;
    while(i < step)
    {
        mlx_put_pixel(cb_data->map_img,x0, y0, 0x008000FF );
        x0 = x0 + x_inc;
        y0 = y0 + y_inc;
        i++;
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

void draw_player(mlx_image_t* player, float player_x, float player_y, t_cub_data *cb_data)
{
	float i = player_x + PLAYER_SIZE;
	float j = player_y + PLAYER_SIZE;
    (void)cb_data;
    cb_data->c_player.end_x = cb_data->c_player.px_dir + player_x;
    cb_data->c_player.end_y = cb_data->c_player.py_dir + player_y;
    float save_x = player_x;
	while (player_y < j)
	{
		player_x = save_x;
		while (player_x < i)
        {
			    mlx_put_pixel(player, player_x, player_y, 0xFF0000FF );
                player_x += 1;
        }
		player_y += 1;
    }
}




void draw_map(t_cub_data *cb_data)
{
    int i;
    int j;
    float x;
    float y;


    i = 0;
    
    y = 0;
    
    while (cb_data->map[i])
    {
        j = 0;
        x = 0;
        while (cb_data->map[i][j])
        {
            if (cb_data->map[i][j] == '1')
                draw_box(cb_data->map_img, x, y, 0x8DC98CFF);
            else
                draw_box(cb_data->map_img, x, y, 0xFFFFFFFF);
            j += 1;
            x += CELL_SIZE;
        }
        y += CELL_SIZE;
        i += 1;
    }
    draw_line_ver(cb_data);
    draw_line_hor(cb_data);
}