/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:31:53 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 20:27:36 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

int	read_map(t_cub_data *cb_data, t_map_data *t_map)
{
	fill_map(cb_data, t_map);
	if (check_erros(cb_data))
		return (-1);
	cb_data->map = t_map->map;
	return (0);
}
