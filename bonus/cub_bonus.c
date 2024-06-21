/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:34:57 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 21:42:47 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	free_imgs(t_cub_data *cb_data)
{
	free(cb_data->north_wall);
	free(cb_data->south_wall);
	free(cb_data->east_wall);
	free(cb_data->west_wall);
}

void	draw_wall(t_cub_data *cb_data, int index)
{
	int	y;

	y = 0;
	while (y < (int)cb_data->tex.pro_height && y < HEIGHT)
	{
		put_pixel(cb_data, index, y);
		cb_data->tex.offset_y += cb_data->tex.step;
		y++;
	}
}

int	main(int ac, char **av)
{
	t_cub_data	cb_data;

	if (ac > 2)
	{
		show_errors("Too many arguments\n");
		return (2);
	}
	if (ac < 2)
	{
		show_errors("Too few arguments\n");
		return (2);
	}
	cb_data.map_name = av[1];
	if (start_game(&cb_data) == -1)
		return (2);
}
