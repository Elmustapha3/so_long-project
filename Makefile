NAME = so_long
CFLAGS = -Wall -Wextra -Werror

FT_SRC = \
	src/so_long.c get_next_line/get_next_line.c src/checking_map.c src/checking_path.c src/frames.c src/move_player.c src/moving_derection.c
	 


FT_SRC_bonus = bonus/so_long_bonus.c get_next_line/get_next_line.c bonus/checking_map_bonus.c bonus/checking_path_bonus.c bonus/frames_bonus.c bonus/move_player_bonus.c bonus/moving_derection_bonus.c


OBJ = $(FT_SRC:.c=.o)

OBJ_bonus = $(FT_SRC_bonus:.c=.o)

all: $(NAME)
	

$(NAME): $(OBJ)
	make -C libft/
	make -C ft_printf/
	cc $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o so_long libft/libft.a ft_printf/libftprintf.a

bonus: $(OBJ_bonus)
	make -C libft/
	make -C ft_printf/
	cc $(CFLAGS) $(OBJ_bonus) -lmlx -framework OpenGL -framework AppKit -o so_long_bonus libft/libft.a ft_printf/libftprintf.a

clean:
	rm -f $(OBJ) $(OBJ_bonus)
	make  -C libft/ clean
	make  -C ft_printf/ clean

fclean: clean
	make  -C libft/ fclean
	make  -C ft_printf/ fclean
	rm -f $(NAME) so_long_bonus

re: fclean all

