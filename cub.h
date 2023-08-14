/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:14:38 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/14 16:55:35 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"


#define MAP_WIDTH 24 * 15
#define MAP_HEIGHT 7 * 15


#define WIDTH 1080
#define HEIGHT 720

#define FOV 60 * (M_PI / 180)
#define NUM_RAYS 1080
#define CELL_SIZE 15
#define PLAYER_SIZE 4


typedef struct s_ray
{
	float ray_angle;
	float distance;
	float hit;
	float hit_side;

} t_ray;

typedef struct s_player
{
	float player_x;
	float player_y;
	float end_x;
	float end_y;
	float px_dir;
	float py_dir;
	float rotation_angle;
	
} t_player;

typedef struct t_cub_data
{
	char *map_name;
	char **map;
	int map_fd;
	mlx_image_t* player;
	mlx_image_t* lines;
	mlx_image_t* map_img;
	mlx_t* mlx;
	t_ray ray;
	t_player c_player;
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
void	draw_player(mlx_image_t* player, int player_x, int player_y, t_cub_data *cb_data);
void	draw_line(int x0, int y0, int x1, int y1,mlx_image_t* map);
void	ray_cast(t_cub_data *cb_data, int player_x, int player_y);
int		is_wall(float x, float y, t_cub_data *cb_data);
void	ft_hook(void* param);
// void	ft_hook(struct mlx_key_data key_data, void *param);

#endif