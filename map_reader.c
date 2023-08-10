/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:31:53 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/07 22:19:38 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



int	read_map(t_cub_data *cb_data)
{
	if (check_erros(cb_data))
		return (-1);
	
	
	cb_data->map = malloc(sizeof(char *) * 8);
	
	cb_data->map[0] = ft_strdup("11111111111");
	cb_data->map[1] = ft_strdup("100P0001001");
	cb_data->map[2] = ft_strdup("10000000001");
	cb_data->map[3] = ft_strdup("10010000001");
	cb_data->map[4] = ft_strdup("10000000001");
	cb_data->map[5] = ft_strdup("10000000001");
	cb_data->map[6] = ft_strdup("11111111111");
	cb_data->map[7] = NULL;
	
	return (0);
}
