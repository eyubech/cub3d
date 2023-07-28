CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c  get_next_line_utils.c cub.c map_reader.c low_fun.c start_game.c

OBJ = $(SRC:.c=.o)

NAME = cub3D

all : $(NAME)


$(NAME) : $(OBJ)

	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean : 
	rm -rf $(OBJ)


fclean : clean
	rm -rf $(NAME)


re : fclean All


