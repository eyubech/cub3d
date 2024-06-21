/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:50:42 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_background(t_cub_data *cb_data)
{
	cb_data->x = 0;
	cb_data->y = 0;
	while (cb_data->x < WIDTH)
	{
		cb_data->y = 0;
		while (cb_data->y < HEIGHT / 2)
		{
			mlx_put_pixel(cb_data->map_img, cb_data->x, cb_data->y,
				cb_data->c_color);
			cb_data->y += 1;
		}
		cb_data->x += 1;
	}
	cb_data->x = 0;
	while (cb_data->x < WIDTH)
	{
		cb_data->y = HEIGHT / 2;
		while (cb_data->y < HEIGHT)
		{
			mlx_put_pixel(cb_data->map_img, cb_data->x, cb_data->y,
				cb_data->f_color);
			cb_data->y += 1;
		}
		cb_data->x += 1;
	}
}

void	draw_line_hor(t_cub_data *cb_data, int index)
{
	float	dx;
	float	dy;
	int		step;
	int		i;

	dx = cb_data->sr[index].hx_inter - cb_data->sr[index].x;
	dy = cb_data->sr[index].hy_inter - cb_data->sr[index].y;
	step = fabs(dx) + fabs(dy);
	i = 0;
	while (i < step)
	{
		if (cb_data->sr[index].x < cb_data->map_width 
			&& cb_data->sr[index].y < cb_data->map_height)
		{
			mlx_put_pixel(cb_data->map_img, cb_data->sr[index].x, 
				cb_data->sr[index].y, 0x0000FFFF);
			cb_data->sr[index].x = cb_data->sr[index].x + (dx / step);
			cb_data->sr[index].y = cb_data->sr[index].y + (dy / step);
		}
		i++;
	}
}

void	draw_line_ver(t_cub_data *cb_data, int index)
{
	float	dx;
	float	dy;
	int		step;
	int		i;

	dx = cb_data->sr[index].vx_inter - cb_data->sr[index].x;
	dy = cb_data->sr[index].vy_inter - cb_data->sr[index].y;
	step = fabs(dx) + fabs(dy);
	i = 0;
	while (i < step)
	{
		if (cb_data->sr[index].x < cb_data->map_width 
			&& cb_data->sr[index].y < cb_data->map_height)
		{
			mlx_put_pixel(cb_data->map_img, cb_data->sr[index].x, 
				cb_data->sr[index].y, 0x0000FFFF);
			cb_data->sr[index].x = cb_data->sr[index].x + (dx / step);
			cb_data->sr[index].y = cb_data->sr[index].y + (dy / step);
		}
		i++;
	}
}

void	draw_box(mlx_image_t *map, int x, int y, uint32_t color)
{
	int	i;
	int	j;
	int	save_x;

	i = x + CELL_SIZE;
	j = y + CELL_SIZE;
	save_x = x;
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

void	draw_map(t_cub_data *cb_data)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	y = 0;
	while (cb_data->map[i])
	{
		j = 0;
		x = 0;
		while (cb_data->map[i][j])
		{
			if (cb_data->map[i][j] == '1')
				draw_box(cb_data->map_img, x, y, 0xCD544AFF);
			else if (cb_data->map[i][j] != ' ')
				draw_box(cb_data->map_img, x, y, 0xFFFFFFFF);
			j += 1;
			x += CELL_SIZE;
		}
		y += CELL_SIZE;
		i += 1;
	}
}
