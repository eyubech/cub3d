CC = cc 



SRC = get_next_line.c  get_next_line_utils.c cub.c map_reader.c low_fun.c start_game.c check_errors.c \
		draw_map.c raycasting.c raycasting_utils.c rendering.c

OBJ = $(SRC:.c=.o)

NAME = cub3D

all : $(NAME)


$(NAME) : $(OBJ)

	$(CC)  libmlx42.a -Iinclude -lglfw -L "$(HOME)/.brew/opt/glfw/lib/"   $(OBJ) -o $(NAME)


clean : 
	rm -rf $(OBJ)


fclean : clean
	rm -rf $(NAME)


re : fclean all

