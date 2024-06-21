CC = cc 

NAME = cub3D
NAME_BONUS = cub3d_bonus

CFLAGS = -Wall -Wextra -Werror



SRC = ./mandatory/get_next_line.c  ./mandatory/get_next_line_utils.c ./mandatory/cub.c ./mandatory/map_reader.c \
			./mandatory/low_fun.c ./mandatory/start_game.c ./mandatory/check_errors.c \
			./mandatory/draw_map.c ./mandatory/raycasting.c ./mandatory/raycasting_utils.c \
			./mandatory/rendering.c ./mandatory/rendering_utils.c ./mandatory/ft_split.c ./mandatory/low_fun2.c \
			./mandatory/textures.c ./mandatory/hook.c ./mandatory/hook_utils.c ./mandatory/additional.c ./mandatory/ft_atoi.c \
			./mandatory/player_checker.c ./mandatory/map_checker.c ./mandatory/map_checker2.c ./mandatory/parse_arg.c\
			./mandatory/parse_arg2.c ./mandatory/parse_arg3.c ./mandatory/parse_arg4.c ./mandatory/draw_map2.c\

SRC_BONUS = ./bonus/get_next_line_bonus.c  ./bonus/get_next_line_utils_bonus.c ./bonus/cub_bonus.c ./bonus/map_reader_bonus.c \
			./bonus/low_fun_bonus.c ./bonus/start_game_bonus.c ./bonus/check_errors_bonus.c \
			./bonus/draw_map_bonus.c ./bonus/raycasting_bonus.c ./bonus/raycasting_utils_bonus.c \
			./bonus/rendering_bonus.c ./bonus/rendering_utils_bonus.c ./bonus/ft_split_bonus.c ./bonus/low_fun2_bonus.c \
			./bonus/textures_bonus.c ./bonus/hook_bonus.c ./bonus/hook_utils_bonus.c ./bonus/additional_bonus.c ./bonus/ft_atoi_bonus.c \
			./bonus/player_checker_bonus.c ./bonus/map_checker_bonus.c ./bonus/map_checker_bonus2.c ./bonus/parse_arg_bonus.c\
			./bonus/parse_arg_bonus2.c ./bonus/parse_arg_bonus3.c ./bonus/parse_arg_bonus4.c ./bonus/draw_map_bonus2.c\
			

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)


all : $(NAME)


bonus : $(NAME_BONUS)


$(NAME) : $(OBJ)

	$(CC)  ./includes/libmlx42.a -Iinclude -lglfw -L "$(HOME)/.brew/opt/glfw/lib/" $(CFLAGS) $(OBJ) -o $(NAME) 

$(NAME_BONUS) : $(OBJ_BONUS)

	$(CC)  ./includes/libmlx42.a -Iinclude -lglfw -L "$(HOME)/.brew/opt/glfw/lib/"  $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) 


clean : 
	rm -rf $(OBJ) $(OBJ_BONUS)


fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)


re : fclean all


