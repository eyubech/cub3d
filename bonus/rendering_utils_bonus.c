/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:54:21 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/31 21:33:34 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

void	texture_mapping(t_cub_data *cb_data, int index)
{
	set_sizes(cb_data, index);
	initialize_vars(cb_data, index);
	set_offset(cb_data, index);
	draw_wall(cb_data, index);
}

void	drawing_walls(t_cub_data *cb_data)
{
	int	index;

	index = 0;
	while (index < NUM_RAYS)
	{
		texture_mapping(cb_data, index);
		index += 1;
	}
}
