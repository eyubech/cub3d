/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:11:04 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 21:38:13 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	ft_initialze(t_cub_data *cb_data, t_map_data *t_map)
{
	search_for_player(cb_data, t_map);
	cb_data->c_player.px_dir = cos(cb_data->c_player.rotation_angle) * 3;
	cb_data->c_player.py_dir = sin(cb_data->c_player.rotation_angle) * 3;
	cb_data->check_draw_map = 1;
	cb_data->pause_game = 2;
	cb_data->check_mouse = 1;
	ft_colors(cb_data);
	cb_data->sr = NULL;
}

void	load_images(t_cub_data *cb_data, t_map_data t_map)
{
	cb_data->north_wall = mlx_load_png(t_map.north_wall);
	cb_data->south_wall = mlx_load_png(t_map.south_wall);
	cb_data->east_wall = mlx_load_png(t_map.east_wall);
	cb_data->west_wall = mlx_load_png(t_map.west_wall);
}

void	check_errors(t_cub_data *cb_data)
{
	if (cb_data->north_wall->height > 1080 || cb_data->north_wall->width > 1080
		|| cb_data->south_wall->height > 1080
		|| cb_data->south_wall->width > 1080
		|| cb_data->east_wall->height > 1080 || cb_data->east_wall->width > 1080
		|| cb_data->west_wall->height > 1080
		|| cb_data->west_wall->width > 1080)
	{
		free_2d(cb_data->map);
		free_imgs(cb_data);
		show_errors("Are you serious, try anothe image like 512 * 512\n");
		exit(2);
	}
	if (cb_data->north_wall->height < 512 || cb_data->north_wall->width < 512
		|| cb_data->south_wall->height < 512 || cb_data->south_wall->width < 512
		|| cb_data->east_wall->height < 512 || cb_data->east_wall->width < 512
		|| cb_data->west_wall->height < 512 || cb_data->west_wall->width < 512)
	{
		free_2d(cb_data->map);
		free_imgs(cb_data);
		show_errors("Are you serious, try anothe image like 512 * 512\n");
		exit(2);
	}
}

void	set_textures(t_cub_data *cb_data)
{
	init_texture(cb_data);
	north_texture(cb_data);
	south_texture(cb_data);
	west_texture(cb_data);
	east_texture(cb_data);
}

int	start_game(t_cub_data *cb_data)
{
	t_map_data	t_map;

	if (read_map(cb_data, &t_map) == -1)
		return (-1);
	cb_data->mlx = mlx_init(WIDTH, HEIGHT, "LOL", false);
	cb_data->map_img = mlx_new_image(cb_data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cb_data->mlx, cb_data->map_img, 0, 0);
	ft_initialze(cb_data, &t_map);
	load_images(cb_data, t_map);
	if (!cb_data->north_wall || !cb_data->south_wall || !cb_data->east_wall
		|| !cb_data->west_wall)
		exit(2);
	check_errors(cb_data);
	set_textures(cb_data);
	draw_background(cb_data);
	ray_cast(cb_data->map_img, cb_data, cb_data->c_player.player_x,
		cb_data->c_player.player_y);
	mlx_set_cursor_mode(cb_data->mlx, MLX_MOUSE_DISABLED);
	mlx_get_mouse_pos(cb_data->mlx, &cb_data->offset_mouse_x,
		&cb_data->offset_mouse_y);
	mlx_loop_hook(cb_data->mlx, ft_hook, cb_data);
	mlx_key_hook(cb_data->mlx, show_map, cb_data);
	mlx_loop(cb_data->mlx);
	return (0);
}
