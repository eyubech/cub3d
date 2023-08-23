/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:11:04 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/23 11:20:51 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	show_map(struct mlx_key_data key_data, void *param)
{
    t_cub_data *cb_data = (t_cub_data *)param;

    
    if (key_data.key == MLX_KEY_M && key_data.action == 0)
    {
        if(cb_data->check_draw_map % 2 == 0)
        {
            draw_background(cb_data->map_img);
            ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x, cb_data->c_player.player_y); 
        }
        else
        {
            draw_map(cb_data);
            draw_map_rays(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
        }
        cb_data->check_draw_map += 1;
    }
    // if (key_data.key == MLX_KEY_P && key_data.action == 0)
    // {
    //     if(cb_data->pause_game % 2 == 0)
    //     {
    //         draw_background(cb_data->map_img);
    //         ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x, cb_data->c_player.player_y); 
    //     }
    //     else
    //     {
    //         draw_map(cb_data);
    //         draw_map_rays(cb_data);
    //         draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
    //     }
    //     cb_data->check_draw_map += 1;
    // }
}

void	ft_hook(void* param)
{
    float next_step_x;
    float next_step_y;
    t_cub_data *cb_data = (t_cub_data *)param;
    
    

    mlx_get_mouse_pos(cb_data->mlx, &cb_data->mouse_x, &cb_data->mouse_y);
    


    
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(cb_data->mlx);

    
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_LEFT) || (cb_data->offset_mouse_x > cb_data->mouse_x))
    {
        cb_data->c_player.rotation_angle -= 0.08;
        if (cb_data->c_player.rotation_angle < 0)
            cb_data->c_player.rotation_angle += 2 * M_PI;
        cb_data->c_player.px_dir = cos(cb_data->c_player.rotation_angle) * 5;
        cb_data->c_player.py_dir = sin(cb_data->c_player.rotation_angle) * 5;

        draw_background(cb_data->map_img);
        ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x, cb_data->c_player.player_y); 
        if(cb_data->check_draw_map % 2 == 0)
        {
            draw_map(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
            draw_map_rays(cb_data);
        }
    }

    
    if (mlx_is_key_down(cb_data->mlx, MLX_KEY_RIGHT) || (cb_data->offset_mouse_x < cb_data->mouse_x) )
    {   
        cb_data->c_player.rotation_angle += 0.08;
        if (cb_data->c_player.rotation_angle >= 2 * M_PI)
            cb_data->c_player.rotation_angle -= 2 * M_PI;
        cb_data->c_player.px_dir = cos(cb_data->c_player.rotation_angle) * 5;
        cb_data->c_player.py_dir = sin(cb_data->c_player.rotation_angle) * 5;
        draw_background(cb_data->map_img);
        ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x, cb_data->c_player.player_y); 
        if(cb_data->check_draw_map % 2 == 0)
        {
            
            draw_map(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
            draw_map_rays(cb_data);
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
        draw_background(cb_data->map_img);
        ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x, cb_data->c_player.player_y); 
        if(cb_data->check_draw_map % 2 == 0)
        {
            draw_map(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
            draw_map_rays(cb_data);
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
        draw_background(cb_data->map_img);
        ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x, cb_data->c_player.player_y); 
        if(cb_data->check_draw_map % 2 == 0)
        {
            draw_map(cb_data);
            draw_player(cb_data->map_img, cb_data->c_player.player_x, cb_data->c_player.player_y , cb_data);
            draw_map_rays(cb_data);
        }
    }
    
    
    cb_data->offset_mouse_x = cb_data->mouse_x;
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

	mlx_image_to_window(mlx, cb_data->map_img, 0, 0);
    cb_data->c_player.rotation_angle = 0.785398;
    cb_data->c_player.px_dir = cos(cb_data->c_player.rotation_angle) * 3;
    cb_data->c_player.py_dir = sin(cb_data->c_player.rotation_angle) * 3;

    cb_data->check_draw_map = 1;
    cb_data->pause_game = 1;
    
    cb_data->north_wall = mlx_load_png("rr.png");
    cb_data->south_wall = mlx_load_png("ff.png");
    cb_data->east_wall = mlx_load_png("dd.png");
    cb_data->west_wall = mlx_load_png("hh.png");
    
    
    cb_data->north_texture = (uint32_t *)malloc(sizeof(uint32_t) *  cb_data->north_wall->height * cb_data->north_wall->width);
    cb_data->south_texture = (uint32_t *)malloc(sizeof(uint32_t) *  cb_data->south_wall->height * cb_data->south_wall->width);
    cb_data->east_texture = (uint32_t *)malloc(sizeof(uint32_t) *  cb_data->east_wall->height * cb_data->east_wall->width);
    cb_data->west_texture = (uint32_t *)malloc(sizeof(uint32_t) *  cb_data->west_wall->height * cb_data->west_wall->width);
    
    
    int i = 0;
    int j = 0;

    int y = 0;
    int z = 0;
    int x = 0;
    
    while(i < cb_data->north_wall->height * cb_data->north_wall->width * sizeof(uint32_t))
    {
        cb_data->north_texture[j] = cb_data->north_wall->pixels[i] << 24 | cb_data->north_wall->pixels[i + 1] << 16 | cb_data->north_wall->pixels[i + 2] << 8 | cb_data->north_wall->pixels[i + 3];
        cb_data->south_texture[j] = cb_data->south_wall->pixels[y] << 24 | cb_data->south_wall->pixels[y + 1] << 16 | cb_data->south_wall->pixels[y + 2] << 8 | cb_data->south_wall->pixels[y + 3];
        
        cb_data->east_texture[j] = cb_data->east_wall->pixels[z] << 24 | cb_data->east_wall->pixels[z + 1] << 16 | cb_data->east_wall->pixels[z + 2] << 8 | cb_data->east_wall->pixels[z + 3];
        cb_data->west_texture[j] = cb_data->west_wall->pixels[x] << 24 | cb_data->west_wall->pixels[x + 1] << 16 | cb_data->west_wall->pixels[x + 2] << 8 | cb_data->west_wall->pixels[x + 3];
        
        i += cb_data->north_wall->bytes_per_pixel;
        y += cb_data->south_wall->bytes_per_pixel;
        z += cb_data->east_wall->bytes_per_pixel;
        x += cb_data->west_wall->bytes_per_pixel;
        
        j++;
    }
    
    draw_background(cb_data->map_img);
    ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x, cb_data->c_player.player_y);
    


    
    mlx_set_cursor_mode(cb_data->mlx, MLX_MOUSE_DISABLED);
    mlx_get_mouse_pos(cb_data->mlx, &cb_data->offset_mouse_x, &cb_data->offset_mouse_y);



	mlx_loop_hook(mlx, ft_hook, cb_data);
    mlx_key_hook(mlx, show_map, cb_data);

	mlx_loop(mlx);

	
	return (0);
}
