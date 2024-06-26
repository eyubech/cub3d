/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:02:32 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/31 21:26:05 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

int	is_wall(float x, float y, t_cub_data *cb_data)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / CELL_SIZE);
	map_y = (int)(y / CELL_SIZE);
	if (cb_data->map[map_x][map_y] == '1')
		return (1);
	return (0);
}

void	normalize_angle(t_cub_data *cb_data)
{
	if (cb_data->ray_angle <= 0)
		cb_data->ray_angle += 2 * M_PI;
	else if (cb_data->ray_angle > 2 * M_PI)
		cb_data->ray_angle -= 2 * M_PI;
}

void	check_horizontal(t_cub_data *cb_data, float delta_x, 
	float delta_y, int colomn)
{
	int	check_h;

	check_h = 0;
	while (cb_data->sr[colomn].hx_inter >= 0 && 
		cb_data->sr[colomn].hx_inter < cb_data->map_width && 
		cb_data->sr[colomn].hy_inter >= 0 && 
		cb_data->sr[colomn].hy_inter < cb_data->map_height)
	{
		if (sin(cb_data->ray_angle) <= 0)
			check_h = cb_data->sr[colomn].hy_inter - 1;
		else
			check_h = cb_data->sr[colomn].hy_inter;
		if (is_wall(check_h, cb_data->sr[colomn].hx_inter, cb_data) == 1)
			break ;
		else
		{
			cb_data->sr[colomn].hy_inter += delta_y;
			cb_data->sr[colomn].hx_inter += delta_x;
		}
	}
}

void	check_vertical(t_cub_data *cb_data, float delta_x,
	float delta_y, int colomn)
{
	int	check_v;

	check_v = 0;
	while (cb_data->sr[colomn].vx_inter >= 0 && 
		cb_data->sr[colomn].vx_inter < cb_data->map_width && 
		cb_data->sr[colomn].vy_inter >= 0 && 
		cb_data->sr[colomn].vy_inter < cb_data->map_height)
	{
		if (cos(cb_data->ray_angle) <= 0)
			check_v = cb_data->sr[colomn].vx_inter - 1;
		else
			check_v = cb_data->sr[colomn].vx_inter ;
		if (is_wall(cb_data->sr[colomn].vy_inter, check_v, cb_data) == 1)
			break ;
		else
		{
			cb_data->sr[colomn].vy_inter += delta_y;
			cb_data->sr[colomn].vx_inter += delta_x;
		}
	}
}
