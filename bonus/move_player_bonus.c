/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:50:43 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/08 16:52:28 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	open_door(t_mlx_vars *m_v)
{
	void	*op;
	t_point	e;

	op = mlx_xpm_file_to_image(m_v->mlx, "textures/open_door.xpm", &m_v->img.i,
			&m_v->img.j);
	e = get_exit(m_v->map);
	mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, op, 50 * e.y, 50 * (e.x));
}

int	close_window(t_mlx_vars *vars)
{
	(void)vars;
	exit(0);
}

int	my_key_hook(int keyboard_key, t_mlx_vars *mlx_vars)
{
	int			num_col;
	static int	printer;
	t_point		p;

	p = get_player(mlx_vars->map);
	num_col = 0;
	if (keyboard_key == 53)
		exit(0);
	if (keyboard_key == 126 || keyboard_key == 13)
		num_col = up(mlx_vars, num_col, &printer, p);
	if (keyboard_key == 125 || keyboard_key == 1)
		num_col = down(mlx_vars, num_col, &printer, p);
	if (keyboard_key == 123 || keyboard_key == 0)
		num_col = left(mlx_vars, num_col, &printer, p);
	if (keyboard_key == 124 || keyboard_key == 2)
		num_col = right(mlx_vars, num_col, &printer, p);
	return (0);
}

void	move_player(t_mlx_vars mlx_vars)
{
	mlx_hook(mlx_vars.mlx_win, 2, 0, my_key_hook, &mlx_vars);
	mlx_hook(mlx_vars.mlx_win, 17, 0, close_window, &mlx_vars);
}
