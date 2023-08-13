/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:02:32 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/12 12:49:24 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int is_wall(float x, float y, t_cub_data *cb_data)
{
	int map_x;
	int map_y;
	map_x = (int)(x/CELL_SIZE);
	map_y = (int)(y/CELL_SIZE);
	if(cb_data->map[map_x][map_y] == '1')
		return(1);
	return(0);	
}