/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:50:42 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/13 15:54:59 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"




void draw_line_ver(mlx_image_t* lines)
{
    int x=0;
    int y=0;

    while (x <= WIDTH)
    {
        y = 0;
        while (y <= HEIGHT)
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

    while (y <= HEIGHT)
    {
        x = 0;
        while (x <= WIDTH)
        {
            if(x <= WIDTH && y <= HEIGHT)
            {
                mlx_put_pixel(lines, x, y, 0x808080FF);
                x += 1;
            }
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
        if(x0 < WIDTH && y0 < HEIGHT)
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
// {
//     int i = 0;
//     float dx = fabs((float)x0 - (float)x1);
//     float dy = fabs((float)y0 - (float)y1);
//     float max = fmax(dx , dy);
//     float step_x = dx / max; // 1
//     float step_y = dy / max; // 0.5
//     float x = x0 ;
//     float y = y0;
//     while (i < max)
//     {
//         mlx_put_pixel(map, x, y, 0x000000);    
//         x += step_x;
//         y += step_y;
//         i++;
//     }
// }
// {
//     int dx = x1 - x0;
//     int dy = y1 - y0;

//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

//     float xIncrement = (float)dx / steps;
//     float yIncrement = (float)dy / steps;

//     float x = x0;
//     float y = y0;

//     for (int i = 0; i <= steps; i++) {
//         mlx_put_pixel(map,x0, y0, 0x008000FF);
//         x += xIncrement;
//         y += yIncrement;
//     }
// }

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
        if(x0 < WIDTH && y0 < HEIGHT)
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
            if(x <= WIDTH && y <= HEIGHT)
			{
                mlx_put_pixel(map, x, y, color);
                x += 1;
            }
        }
		y += 1;
	}
}

void draw_player(mlx_image_t* player, int player_x, int player_y, t_cub_data *cb_data)
{
	// int i = player_x + 16;
	// int j = player_y + 16;
    // (void)cb_data;
    // cb_data->c_player.end_x = cb_data->c_player.px_dir + player_x;
    // cb_data->c_player.end_y = cb_data->c_player.py_dir + player_y;
    // float save_x = player_x;
	// while (player_y < j)
	// {
	// 	player_x = save_x;
	// 	while (player_x < i)
    //     {
    //         if(player_x <= WIDTH && player_y <= HEIGHT)
    //         {
	// 		    mlx_put_pixel(player, player_x, player_y, 0xFF0000FF);
    //             player_x += 1;
    //         }
    //     }
	// 	player_y += 1;
	// }
    ray_cast(cb_data, player_x, player_y); 
    draw_curs(player_x , player_y , player_x + cos(cb_data->c_player.rotation_angle) * 50, player_y + sin(cb_data->c_player.rotation_angle)*50,player);
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
            x += CELL_SIZE;
        }
        y += CELL_SIZE;
        i += 1;
    }
    draw_line_ver(cb_data->map_img);
    draw_line_hor(cb_data->map_img);
}