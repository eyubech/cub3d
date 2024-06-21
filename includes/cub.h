/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:14:38 by aech-che          #+#    #+#             */
/*   Updated: 2023/08/31 22:50:09 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../../../Desktop/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1080
# define HEIGHT 720
# define FOV 1.0471975511965976
# define NUM_RAYS 1080

# define CELL_SIZE 15

typedef struct s_ray
{
	float	ray_angle;
	float	r_distance;
	float	player_rotation_angle;
	float	hit;
	float	hit_side;
	float	hx_inter;
	float	hy_inter;
	float	vx_inter;
	float	vy_inter;
	float	hor_dist;
	float	ver_dist;
	float	x;
	float	y;
}	t_ray;

typedef struct s_player
{
	float	player_x;
	float	player_y;
	float	end_x;
	float	end_y;
	float	px_dir;
	float	py_dir;
	float	rotation_angle;
}	t_player;

typedef struct s_texture
{
	float	pro_height;
	float	corr_dist;
	float	alpha;
	float	start;
	float	offset_x;
	float	offset_y;
	float	e;
	float	step;
	float	pro_dist;
	int		width;
	int		height;
}	t_texture;

typedef struct t_map_parsing_data
{
	int		line;
	int		count;
	char	*readed;
	char	**readed_splited;
	char	*west_wall;
	char	*south_wall;
	char	*east_wall;
	char	*north_wall;
	char	**f_color;
	char	**c_color;
	int		error_code;
	int		map_size;
	char	**map;
	int		i;
	int		counter;
	int		y;
	int		j;
	int		c;
	int		valid_line;
	int		fd;
	char	*s;
	int		map_area;

}	t_map_data;

typedef struct t_cub_data
{
	char			*map_name;
	char			**map;
	int				map_fd;
	int				load_img_code;
	int				check_draw_map;
	mlx_image_t		*map_img;
	mlx_t			*mlx;
	t_ray			ray;
	t_player		c_player;
	float			ray_angle;
	t_ray			*sr;
	int				pause_game;
	mlx_texture_t	*west_wall;
	mlx_texture_t	*south_wall;
	mlx_texture_t	*east_wall;
	mlx_texture_t	*north_wall;
	uint32_t		*north_texture;
	uint32_t		*south_texture;
	uint32_t		*east_texture;
	uint32_t		*west_texture;
	int				offset_mouse_x;
	int				offset_mouse_y;
	int				mouse_x;
	int				mouse_y;
	int				check_mouse;
	int				dont_show_map;
	int				map_width;
	int				map_height;
	int				c_red;
	int				c_green;
	int				c_blue;
	int				f_red;
	int				f_green;
	int				f_blue;
	uint32_t		c_color;
	uint32_t		f_color;
	t_texture		tex;
	int				x;
	int				y;
}	t_cub_data;

int		ft_strlen(char *s);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	show_errors(char *message);
int		start_game(t_cub_data *cb_data);
int		suff_error(t_cub_data *cb_data);
int		check_erros(t_cub_data *cb_data);
char	*ft_strtrim(char *s1, char *set);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
void	draw_map(t_cub_data *cb_data);
void	draw_box(mlx_image_t *map, int x, int y, uint32_t color);
int		is_wall(float x, float y, t_cub_data *cb_data);
void	ft_hook(void *param);
void	draw_background(t_cub_data *cb_data);
void	draw_pause_icon(t_cub_data *cb_data);
void	drawing_walls(t_cub_data *cb_data);
void	draw_map_rays(t_cub_data *cb_data);
char	**ft_split(char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_2d(char **s);
void	fill_map(t_cub_data *cb_data, t_map_data *t_map);
int		read_map(t_cub_data *cb_data, t_map_data *t_map);
char	*rm_nl(char *s1);
void	parse_arg(t_cub_data *cb_data, t_map_data *t_map);
void	*ft_calloc(size_t count, size_t size);
void	ray_cast(mlx_image_t *player, t_cub_data *cb_data, 
			float player_x, float player_y);
void	draw_wall(t_cub_data *cb_data, int index);
void	put_pixel(t_cub_data *cb_data, int index, int y);
void	set_offset(t_cub_data *cb_data, int index);
void	initialize_vars(t_cub_data *cb_data, int index);
void	set_sizes(t_cub_data *cb_data, int index);
void	draw_map_rays(t_cub_data *cb_data);
void	normalize_angle(t_cub_data *cb_data);
void	check_horizontal(t_cub_data *cb_data, 
			float delta_x, float delta_y, int colomn);
void	check_vertical(t_cub_data *cb_data, float delta_x,
			float delta_y, int colomn);
void	load_images(t_cub_data *cb_data, t_map_data t_map);
void	init_texture(t_cub_data *cb_data);
void	north_texture(t_cub_data *cb_data);
void	south_texture(t_cub_data *cb_data);
void	west_texture(t_cub_data *cb_data);
void	east_texture(t_cub_data *cb_data);
void	ft_hook(void *param);
void	a_case(t_cub_data *cb_data);
void	d_case(t_cub_data *cb_data);
void	s_case(t_cub_data *cb_data);
void	w_case(t_cub_data *cb_data);
void	right_case(t_cub_data *cb_data);
void	left_case(t_cub_data *cb_data);
void	update_player_y(t_cub_data *cb_data, int next_step_x,
			int next_step_y, int check);
void	update_player_x(t_cub_data *cb_data, int next_step_x, 
			int next_step_y, int check);
void	case_one(struct mlx_key_data key_data, t_cub_data *cb_data);
void	case_two(struct mlx_key_data key_data, t_cub_data *cb_data);
void	case_three(struct mlx_key_data key_data, t_cub_data *cb_data);
void	show_map(struct mlx_key_data key_data, void *param);
void	search_for_player(t_cub_data *cb_data, t_map_data *t_map);
int		ft_atoi(const char *str);
void	ft_colors(t_cub_data *cb_data);
void	init_player(t_cub_data *cb_data, t_map_data *t_map, int i, int j);
int		player_open_world(t_cub_data *cb_data, t_map_data *t_map, int i, int j);
void	player_error_exit(t_cub_data *cb_data);
int		is_player(char c);
void	found_hole(t_cub_data *cb_data, t_map_data *t_map, int i, int j);
void	zero_in_borders(t_cub_data *cb_data, t_map_data *t_map, int i, int j);
void	invalid_map(t_map_data *t_map);
void	check_big_small_map(t_cub_data *cb_data, t_map_data *t_map);
void	check_game_map(t_map_data *t_map);
void	init_data(t_cub_data *cb_data, t_map_data *t_map);
void	dup_elements(t_map_data *t_map);
void	init_data_map(t_cub_data *cb_data, t_map_data *t_map);
void	parse_c_color(t_cub_data *cb_data, t_map_data *t_map);
void	parse_f_color(t_cub_data *cb_data, t_map_data *t_map);
int		count_el(char **s);
void	parse_colors(t_cub_data *cb_data, t_map_data *t_map);
void	map_errors_msg(t_map_data *t_map);
void	check_count(t_map_data *t_map);
void	count_map_size(t_cub_data *cb_data, t_map_data *t_map);
void	helping_parse(t_cub_data *cb_data, t_map_data *t_map);
int		is_map_begin(char *s);
int		suff_error(t_cub_data *cb_data);
void	fill_map(t_cub_data *cb_data, t_map_data *t_map);
void	draw_line_hor(t_cub_data *cb_data, int index);
void	draw_line_ver(t_cub_data *cb_data, int index);
int		ft_isdigit(int c);
int		is_nl(char *s);
void	free_imgs(t_cub_data *cb_data);

#endif