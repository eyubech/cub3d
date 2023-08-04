/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:11:04 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/04 17:34:27 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	ft_hook(struct mlx_key_data key_data, void *param)
void	ft_hook(void* param)
{
    int next_step_x;
    int next_step_y;
    t_cub_data *cb_data = (t_cub_data *)param;

    // (void)key_data;

    // printf("** %f\n **", cb_data->rotation_angle);
    
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(cb_data->mlx);




    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_LEFT))
    {
        cb_data->rotation_angle -= 0.05;
        if (cb_data->rotation_angle < 0)
            cb_data->rotation_angle += 2 * M_PI;
        cb_data->px_dir = cos(cb_data->rotation_angle) * 5;
        cb_data->py_dir = sin(cb_data->rotation_angle) * 5;

        
    }

    
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_RIGHT))
    {   
        cb_data->rotation_angle += 0.05;
        if (cb_data->rotation_angle >= 2 * M_PI)
            cb_data->rotation_angle -= 2 * M_PI;
        cb_data->px_dir = cos(cb_data->rotation_angle) * 5;
        cb_data->py_dir = sin(cb_data->rotation_angle) * 5;
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_UP))
    {
        next_step_x = cb_data->player_x + cb_data->px_dir;
        next_step_y = cb_data->player_y + cb_data->py_dir;
        if(cb_data->map[((int)next_step_y + 16) / 50][((int)next_step_x + 16) / 50] != '1')
        {
            cb_data->player_x += cb_data->px_dir;
            cb_data->player_y += cb_data->py_dir;
        }
    }
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_DOWN))
    {
        next_step_x = cb_data->player_x - cb_data->px_dir;
        next_step_y = cb_data->player_y - cb_data->py_dir;
        if(cb_data->map[((int)next_step_y + 16) / 50][((int)next_step_x + 16) / 50] != '1')
        {
            cb_data->player_x -= cb_data->px_dir;
            cb_data->player_y -= cb_data->py_dir;
            
        }
        
    }
    draw_map(cb_data, cb_data->mlx);
    draw_player(cb_data->map_img, cb_data->player_x, cb_data->player_y , cb_data);
}

int start_game(t_cub_data *cb_data)
{
    if (read_map(cb_data) == -1)
		return (-1);
	
	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Happy Happy", false);
	
	cb_data->mlx = mlx;
	 
	cb_data->player_x = 200;
	cb_data->player_y = 200;
	cb_data->map_img = mlx_new_image(mlx, 550, 550);
    // cb_data->lines = mlx_new_image(mlx, 550, 550);
    // cb_data->player = mlx_new_image(mlx, 550, 550);
	mlx_image_to_window(mlx, cb_data->map_img, 0, 0);
    // mlx_image_to_window(mlx, cb_data->lines, 0, 0);
    // mlx_image_to_window(mlx, cb_data->player, 0, 0);
	
    cb_data->rotation_angle = M_PI_2;
    // cb_data->px_dir = 0;
    // cb_data->px_dir = 0;
    cb_data->px_dir = cos(cb_data->rotation_angle) * 3;
    cb_data->py_dir = sin(cb_data->rotation_angle) * 3;
    
	mlx_loop_hook(mlx, ft_hook, cb_data);
	// mlx_key_hook(mlx, ft_hook, cb_data);

	mlx_loop(mlx);

	
	return (0);
}