/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:14:38 by aech-che          #+#    #+#             */
/*   Updated: 2023/07/30 16:40:13 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 550
#define HEIGHT 350


typedef struct t_cub_data
{
	char *map_name;
	char **map;
	int map_fd;
	int player_x;
	int player_y;
	mlx_t* mlx;
}	t_cub_data;



size_t	ft_strlen(char *s);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void    show_errors(char *message);
int    start_game(t_cub_data *cb_data);
int    read_map(t_cub_data *cb_data);
int		suff_error(t_cub_data *cb_data);
int		check_erros(t_cub_data *cb_data);
char	*ft_strtrim(char *s1, char *set);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
void	draw_map(t_cub_data *cb_data, mlx_t* mlx);
void	ft_hook(void* param);
#endif