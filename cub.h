/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:14:38 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/22 18:03:25 by aech-che         ###   ########.fr       */
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

#define TEXTURE_WIDTH 15
#define TEXTURE_HEIGHT 15

typedef struct s_ray
{
	float ray_angle;
	float r_distance;
	float player_rotation_angle;
	float hit;
	float hit_side;
	float hx_inter;
	float hy_inter;
	float vx_inter;
	float vy_inter;
	float hor_dist;
	float ver_dist;
	float x;
	float y;
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
	
	int check_draw_map;
	mlx_image_t* map_img;
	mlx_t* mlx;
	t_ray ray;
	t_player c_player;
	float ray_angle;
	t_ray *sr;
	int pause_game;

	mlx_texture_t *west_wall;
	mlx_texture_t *south_wall;
	mlx_texture_t *east_wall;
	mlx_texture_t *north_wall;
	
	uint32_t *north_texture;
	uint32_t *south_texture;
	uint32_t *east_texture;
	uint32_t *west_texture;


	
	int offset_mouse_x;
	int offset_mouse_y;
	int mouse_x;
	int mouse_y;
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
void	draw_map(t_cub_data *cb_data);
void	draw_line_ver(mlx_image_t* lines);
void	draw_line_hor(mlx_image_t* lines);
void	draw_box(mlx_image_t* map, int x, int y, uint32_t color);
void	draw_player(mlx_image_t* player, float player_x, float player_y, t_cub_data *cb_data);
void	draw_line(float x0, float y0, float x1, float y1,mlx_image_t* map);
void	ray_cast(mlx_image_t *player, t_cub_data *cb_data, float player_x, float player_y);
int		is_wall(float x, float y, t_cub_data *cb_data);
void	ft_hook(void* param);
void	draw_background(mlx_image_t* background);
// void	ft_hook(struct mlx_key_data key_data, void *param);
void	drawing_walls(t_cub_data *cb_data);
void	draw_map_rays(t_cub_data *cb_data);

void	texture_mapping(t_cub_data *cb_data);

#endif