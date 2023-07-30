/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:50:42 by aech-che          #+#    #+#             */
/*   Updated: 2023/07/30 21:18:33 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void ft_hook(void* param)
{
	t_cub_data *cb_data = param;

     
	if (mlx_is_key_down(cb_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cb_data->mlx);
    
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_RIGHT))
    {
        cb_data->player_x += 2;
        // draw_map(cb_data, cb_data->mlx);
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_LEFT))
    {
        cb_data->player_x -= 2;
        // draw_map(cb_data, cb_data->mlx);
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_UP))
    {
        cb_data->player_y -= 2;
        // draw_map(cb_data, cb_data->mlx);
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_DOWN))
    {
        cb_data->player_y += 2;
    }
        draw_map(cb_data, cb_data->mlx);
        draw_player(cb_data->map_img, cb_data->player_x, cb_data->player_y);
    
}

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

void draw_player(mlx_image_t* player, int player_x, int player_y)
{
	int i = player_x + 15;
	int j = player_y + 15;
    int save_x = player_x;
	
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
    // draw_player(cb_data->player, cb_data->player_x, cb_data->player_y);
    

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