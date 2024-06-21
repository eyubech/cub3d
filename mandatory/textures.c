/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:49:57 by nel-mous          #+#    #+#             */
/*   Updated: 2023/08/31 22:39:54 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_texture(t_cub_data *cb_data)
{
	cb_data->east_texture = ft_calloc(sizeof(uint32_t),
			(cb_data->east_wall->height * cb_data->east_wall->width + 1));
	cb_data->west_texture = ft_calloc(sizeof(uint32_t),
			(cb_data->west_wall->height * cb_data->west_wall->width + 1));
	cb_data->north_texture = ft_calloc(sizeof(uint32_t),
			(cb_data->north_wall->height * cb_data->north_wall->width + 1));
	cb_data->south_texture = ft_calloc(sizeof(uint32_t),
			(cb_data->south_wall->height * cb_data->south_wall->width + 1));
}

void	north_texture(t_cub_data *cb_data)
{
	unsigned long	i;
	int				j;

	i = 0;
	j = 0;
	while (i < cb_data->north_wall->height * cb_data->north_wall->width
		* sizeof(uint32_t))
	{
		cb_data->north_texture[j] = cb_data->north_wall->pixels[i] << 24
			| cb_data->north_wall->pixels[i
			+ 1] << 16 | cb_data->north_wall->pixels[i
			+ 2] << 8 | cb_data->north_wall->pixels[i + 3];
		i += cb_data->north_wall->bytes_per_pixel;
		j++;
	}
}

void	south_texture(t_cub_data *cb_data)
{
	unsigned long	i;
	int				j;

	i = 0;
	j = 0;
	while (i < cb_data->south_wall->height * cb_data->south_wall->width
		* sizeof(uint32_t))
	{
		cb_data->south_texture[j] = cb_data->south_wall->pixels[i] << 24
			| cb_data->south_wall->pixels[i
			+ 1] << 16 | cb_data->south_wall->pixels[i
			+ 2] << 8 | cb_data->south_wall->pixels[i + 3];
		i += cb_data->south_wall->bytes_per_pixel;
		j++;
	}
}

void	west_texture(t_cub_data *cb_data)
{
	unsigned long	i;
	int				j;

	i = 0;
	j = 0;
	while (i < cb_data->west_wall->height * cb_data->west_wall->width
		* sizeof(uint32_t))
	{
		cb_data->west_texture[j] = cb_data->west_wall->pixels[i] << 24
			| cb_data->west_wall->pixels[i
			+ 1] << 16 | cb_data->west_wall->pixels[i
			+ 2] << 8 | cb_data->west_wall->pixels[i + 3];
		i += cb_data->west_wall->bytes_per_pixel;
		j++;
	}
}

void	east_texture(t_cub_data *cb_data)
{
	unsigned long	i;
	int				j;

	i = 0;
	j = 0;
	while (i < cb_data->east_wall->height * cb_data->east_wall->width
		* sizeof(uint32_t))
	{
		cb_data->east_texture[j] = cb_data->east_wall->pixels[i] << 24
			| cb_data->east_wall->pixels[i
			+ 1] << 16 | cb_data->east_wall->pixels[i
			+ 2] << 8 | cb_data->east_wall->pixels[i + 3];
		i += cb_data->east_wall->bytes_per_pixel;
		j++;
	}
}
