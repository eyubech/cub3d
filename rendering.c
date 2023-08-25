/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:57:39 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/25 19:16:14 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	texture_mapping(t_cub_data *cb_data, int index)
{
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
