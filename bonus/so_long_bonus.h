/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:48:50 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/08 16:53:32 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BUFFER_SIZE 100
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_point
{
	int			x;
	int			y;
}				t_point;

typedef struct t_images
{
	void		*wll;
	void		*plyr;
	void		*coll;
	void		*exit;
	void		*spc;
	int			i;
	int			j;
}				t_images;

typedef struct t_maps
{
	char		**map;
	char		**map1;
	char		**map2;
}				t_maps;

typedef struct t_mlx_vars
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_images	img;
	int			i;
	int			j;
}				t_mlx_vars;

typedef struct t_positions
{
	t_point		old_pos;
	t_point		new_pos;
}				t_positions;

char			*get_next_line(int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			check_map(char **map, char *str, char *file);
void			error_and_exit(void);
void			check_empty_and_nl(char *str);
void			check_p_e_c(char *str);
void			check_walls(char **map);
void			check_rectangle(char **map);
void			check_extension_and_content(char *str, char *file);
int				valid_path(char **map, char c, int x, int y);
int				get_nbr_c(char **map);
t_point			get_player(char **map);
void			window_display(char **map);
void			move_player(t_mlx_vars mlx_vars);
int				up(t_mlx_vars *mlx_vars, int num_col, int *printer, t_point p);
int				down(t_mlx_vars *mlx_vars, int num_col, int *printer,
					t_point p);
int				left(t_mlx_vars *mlx_vars, int num_col, int *printer,
					t_point p);
int				right(t_mlx_vars *mlx_vars, int num_col, int *printer,
					t_point p);
t_point			get_exit(char **map);
void			open_door(t_mlx_vars *m_v);

#endif