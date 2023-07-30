/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:11:04 by aech-che          #+#    #+#             */
/*   Updated: 2023/07/30 18:50:23 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



int start_game(t_cub_data *cb_data)
{
    if (read_map(cb_data) == -1)
		return (-1);
	
	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Happy Happy", true);
	
	cb_data->mlx = mlx;
	
	cb_data->player_x = 10;
	cb_data->player_y = 20;
	mlx_loop_hook(mlx, ft_hook, cb_data);
	draw_map(cb_data, mlx);
	

	mlx_loop(mlx);

	
	return (0);
}