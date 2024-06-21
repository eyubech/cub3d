/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:15:44 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_colors(t_cub_data *cb_data)
{
	cb_data->c_color = (cb_data->c_red << 24 
			| cb_data->c_green << 16 | cb_data->c_blue << 8 | 255);
	cb_data->f_color = cb_data->f_red << 24 
		| cb_data->f_green << 16 | cb_data->f_blue << 8 | 255;
}

void	draw_pause_icon(t_cub_data *cb_data)
{
	cb_data->x = (WIDTH / 2) - 80;
	cb_data->y = (HEIGHT / 2) - 50;
	while (cb_data->x < ((WIDTH / 2) - 80) + 40)
	{
		cb_data->y = (HEIGHT / 2) - 50;
		while (cb_data->y < ((HEIGHT / 2) - 50) + 140)
		{
			mlx_put_pixel(cb_data->map_img, cb_data->x, cb_data->y, 0x008081FF);
			cb_data->y += 1;
		}
		cb_data->x += 1;
	}
	cb_data->x = (WIDTH / 2);
	cb_data->y = (HEIGHT / 2) - 50;
	while (cb_data->x < ((WIDTH / 2)) + 40)
	{
		cb_data->y = (HEIGHT / 2) - 50;
		while (cb_data->y < ((HEIGHT / 2) - 50) + 140)
		{
			mlx_put_pixel(cb_data->map_img, cb_data->x, cb_data->y, 0x008081FF);
			cb_data->y += 1;
		}
		cb_data->x += 1;
	}
}
