/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:14:38 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/03 15:40:56 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "MLX42/include/MLX42/MLX42.h"
#include <math.h>

#define WIDTH 550
#define HEIGHT 350

typedef struct t_cub_data
{
	char *map_name;
	char **map;
	int map_fd;
	float player_x;
	float player_y;
	float end_x;
	float end_y;
	mlx_image_t* player;
	mlx_image_t* lines;
	mlx_image_t* map_img;
	mlx_t* mlx;
	float px_dir; //turn_direction
	float py_dir; //walkdirection
	float rotation_angle;
	float move_step;
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
void	draw_line_ver(mlx_image_t* lines);
void	draw_line_hor(mlx_image_t* lines);
void	draw_box(mlx_image_t* map, int x, int y, uint32_t color);
void draw_player(mlx_image_t* player, int player_x, int player_y, t_cub_data *cb_data);
void	ft_dda(mlx_image_t* map, int p1_x, int p1_y, int p2_x, int p2_y);




void	ft_hook(void* param);
// void	ft_hook(struct mlx_key_data key_data, void *param);



#endif