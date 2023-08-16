/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:57:39 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/15 12:58:03 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void drawing_walls(mlx_image_t* lines,t_cub_data *cb_data, int index)
{
	// printf("%p\n", lines);
	int y;
	float Projected_Wall_Height;
	float Dis_From_Proplane;

	Dis_From_Proplane = (WIDTH / 2) / tan(FOV / 2);
	Projected_Wall_Height = (CELL_SIZE / cb_data->ray.r_distance) * Dis_From_Proplane;
	float start = HEIGHT / 2 - Projected_Wall_Height / 2;
	if(start < 0)
		start = 0;
	// printf("dist:%f\n",Projected_Wall_Height );
	y = 0;
	while(y < Projected_Wall_Height && y < HEIGHT)
	{
		mlx_put_pixel(lines, index, start + y, 0xFFFFFF);
		y++;
	}
}