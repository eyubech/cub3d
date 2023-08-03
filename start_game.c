/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:11:04 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/03 12:23:43 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ft_hook(void* param)
{
    t_cub_data *cb_data = param;

    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(cb_data->mlx);
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_LEFT))
    {
        cb_data->rotation_angle -= 0.05;
        cb_data->end_y -= 0.05;
        if (cb_data->rotation_angle < 0)
            cb_data->rotation_angle += 2 * M_PI;
        cb_data->px_dir = cos(cb_data->rotation_angle) * 5;
        cb_data->py_dir = sin(cb_data->rotation_angle) * 5;
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_RIGHT))
    {   
        cb_data->rotation_angle += 0.05;
        cb_data->end_y += 0.05;
        if (cb_data->rotation_angle >= 2 * M_PI)
            cb_data->rotation_angle -= 2 * M_PI;
        cb_data->px_dir = cos(cb_data->rotation_angle) * 5;
        cb_data->py_dir = sin(cb_data->rotation_angle) * 5;
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_UP))
    {
        cb_data->player_x -= cb_data->px_dir;
        cb_data->player_y -= cb_data->py_dir;
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_DOWN))
    {
        cb_data->player_x += cb_data->px_dir;
        cb_data->player_y += cb_data->py_dir;
    }
    // cb_data->px_dir = cb_data->px_dir * cos(cb_data->rotation_angle) - cb_data->py_dir * sin(cb_data->rotation_angle);
    // cb_data->py_dir = cb_data->px_dir * sin(cb_data->rotation_angle) + cb_data->py_dir * cos(cb_data->rotation_angle);
    draw_map(cb_data, cb_data->mlx);
    draw_player(cb_data->map_img, (cb_data->player_x + cb_data->px_dir * 5), (cb_data->player_y + cb_data->py_dir * 5), cb_data);
}

int start_game(t_cub_data *cb_data)
{
    if (read_map(cb_data) == -1)
		return (-1);
	
	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Happy Happy", true);
	
	cb_data->mlx = mlx;
	
	cb_data->player_x = 200;
	cb_data->player_y = 200;
	cb_data->map_img = mlx_new_image(mlx, 550, 550);
    // cb_data->lines = mlx_new_image(mlx, 550, 550);
    // cb_data->player = mlx_new_image(mlx, 550, 550);
	mlx_image_to_window(mlx, cb_data->map_img, 0, 0);
    // mlx_image_to_window(mlx, cb_data->lines, 0, 0);
    // mlx_image_to_window(mlx, cb_data->player, 0, 0);
	
    cb_data->rotation_angle = 90 * (M_PI / 180);
    // cb_data->px_dir = 0;
    // cb_data->px_dir = 0;
    cb_data->px_dir = cos(cb_data->rotation_angle) * 3;
    cb_data->py_dir = sin(cb_data->rotation_angle) * 3;
    cb_data->end_x = cb_data->player_x + 10;
    cb_data->end_y = cb_data->player_y + 10;
    
	mlx_loop_hook(mlx, ft_hook, cb_data);
	

	mlx_loop(mlx);

	
	return (0);
}