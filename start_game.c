/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:11:04 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/15 21:41:56 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	show_map(struct mlx_key_data key_data, void *param)
{
    t_cub_data *cb_data = (t_cub_data *)param;

    
    if (key_data.key == MLX_KEY_M && key_data.action == 0)
    {
        if(cb_data->check_draw_map % 2 == 0)
            draw_background(cb_data->map_img);
        else
        {
            draw_map(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
        }
        cb_data->check_draw_map += 1;
    }
}
void	ft_hook(void* param)
{
    int next_step_x;
    int next_step_y;
    t_cub_data *cb_data = (t_cub_data *)param;
    
    // int i = 0;
    // while (i < NUM_RAYS)
    // {
    //     drawing_walls(cb_data->map_img, cb_data, i);
    //     i += 1;
    // }
    
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(cb_data->mlx);

    
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_LEFT))
    {
        cb_data->c_player.rotation_angle -= 0.03;
        if (cb_data->c_player.rotation_angle < 0)
            cb_data->c_player.rotation_angle += 2 * M_PI;
        cb_data->c_player.px_dir = cos(cb_data->c_player.rotation_angle) * 5;
        cb_data->c_player.py_dir = sin(cb_data->c_player.rotation_angle) * 5;

        if(cb_data->check_draw_map % 2 == 0)
        {
            draw_map(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
        }
        
    }

    
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_RIGHT))
    {   
        cb_data->c_player.rotation_angle += 0.03;
        if (cb_data->c_player.rotation_angle >= 2 * M_PI)
            cb_data->c_player.rotation_angle -= 2 * M_PI;
        cb_data->c_player.px_dir = cos(cb_data->c_player.rotation_angle) * 5;
        cb_data->c_player.py_dir = sin(cb_data->c_player.rotation_angle) * 5;
        if(cb_data->check_draw_map % 2 == 0)
        {
            draw_map(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
        }
        
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_UP))
    {
        next_step_x = cb_data->c_player.player_x + cb_data->c_player.px_dir;
        next_step_y = cb_data->c_player.player_y + cb_data->c_player.py_dir;
        if(cb_data->map[((int)next_step_y + PLAYER_SIZE) / CELL_SIZE][((int)next_step_x + PLAYER_SIZE) / CELL_SIZE] != '1')
        {
            cb_data->c_player.player_x += cb_data->c_player.px_dir / 4;
            cb_data->c_player.player_y += cb_data->c_player.py_dir / 4;
        }
        if(cb_data->check_draw_map % 2 == 0)
        {
            draw_map(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
        }
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_DOWN))
    {
        next_step_x = cb_data->c_player.player_x - cb_data->c_player.px_dir;
        next_step_y = cb_data->c_player.player_y - cb_data->c_player.py_dir;
        if(cb_data->map[((int)next_step_y + PLAYER_SIZE) / CELL_SIZE][((int)next_step_x + PLAYER_SIZE) / CELL_SIZE] != '1')
        {
            cb_data->c_player.player_x -= cb_data->c_player.px_dir / 4;
            cb_data->c_player.player_y -= cb_data->c_player.py_dir / 4;
            
        }
        if(cb_data->check_draw_map % 2 == 0)
        {
            draw_map(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
            
        }
    }
    
    
    
    
}

int start_game(t_cub_data *cb_data)
{
    if (read_map(cb_data) == -1)
		return (-1);
	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "LOL", false);
	cb_data->mlx = mlx;
	cb_data->c_player.player_x = 100;
	cb_data->c_player.player_y = 50;
    

    
    
	cb_data->map_img = mlx_new_image(mlx, WIDTH, HEIGHT);

    cb_data->background = mlx_new_image(mlx, WIDTH, HEIGHT);    
	mlx_image_to_window(mlx, cb_data->map_img, 0, 0);
    cb_data->c_player.rotation_angle = 0.785398;
    cb_data->c_player.px_dir = cos(cb_data->c_player.rotation_angle) * 3;
    cb_data->c_player.py_dir = sin(cb_data->c_player.rotation_angle) * 3;
    draw_background(cb_data->map_img);

    cb_data->check_draw_map = 1;

    
	mlx_loop_hook(mlx, ft_hook, cb_data);
    
	mlx_key_hook(mlx, show_map, cb_data);

	mlx_loop(mlx);

	
	return (0);
}