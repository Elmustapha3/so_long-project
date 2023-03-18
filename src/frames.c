/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:49:58 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/08 22:35:39 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	st_strlenc(char **map)
{
	int	lenc;

	lenc = 0;
	while (map[lenc])
		lenc++;
	return (lenc);
}

void	dispaly_images(t_mlx_vars m_v)
{
	m_v.i = 0;
	while (m_v.map[m_v.i])
	{
		m_v.j = 0;
		while (m_v.map[m_v.i][m_v.j])
		{
			mlx_put_image_to_window(m_v.mlx, m_v.mlx_win, m_v.img.spc, 50
				* m_v.j, 50 * m_v.i);
			if (m_v.map[m_v.i][m_v.j] == '1')
				mlx_put_image_to_window(m_v.mlx, m_v.mlx_win, m_v.img.wll, 50
					* m_v.j, 50 * m_v.i);
			if (m_v.map[m_v.i][m_v.j] == 'P')
				mlx_put_image_to_window(m_v.mlx, m_v.mlx_win, m_v.img.plyr, 50
					* m_v.j, 50 * m_v.i);
			if (m_v.map[m_v.i][m_v.j] == 'C')
				mlx_put_image_to_window(m_v.mlx, m_v.mlx_win, m_v.img.coll, 50
					* m_v.j, 50 * m_v.i);
			if (m_v.map[m_v.i][m_v.j] == 'E')
				mlx_put_image_to_window(m_v.mlx, m_v.mlx_win, m_v.img.exit, 50
					* m_v.j, 50 * m_v.i);
			m_v.j++;
		}
		m_v.i++;
	}
}

void	window_display(char **map)
{
	t_mlx_vars	mlx_vars;

	mlx_vars.mlx = mlx_init();
	mlx_vars.map = map;
	mlx_vars.mlx_win = mlx_new_window(mlx_vars.mlx, 50 * ft_strlen(map[0]),
			50 * st_strlenc(map), "my first game!");
	mlx_vars.img.wll = mlx_xpm_file_to_image(mlx_vars.mlx,
			"textures/walls.xpm", &mlx_vars.img.i, &mlx_vars.img.j);
	mlx_vars.img.exit = mlx_xpm_file_to_image(mlx_vars.mlx,
			"textures/close_door.xpm", &mlx_vars.img.i, &mlx_vars.img.j);
	mlx_vars.img.spc = mlx_xpm_file_to_image(mlx_vars.mlx,
			"textures/new_one.xpm", &mlx_vars.img.i, &mlx_vars.img.j);
	mlx_vars.img.plyr = mlx_xpm_file_to_image(mlx_vars.mlx,
			"textures/new_player.xpm", &mlx_vars.img.i, &mlx_vars.img.j);
	mlx_vars.img.coll = mlx_xpm_file_to_image(mlx_vars.mlx,
			"textures/money.xpm", &mlx_vars.img.i, &mlx_vars.img.j);
	if (!mlx_vars.img.coll || !mlx_vars.img.wll || !mlx_vars.img.exit
		|| !mlx_vars.img.spc || !mlx_vars.img.plyr)
		error_and_exit();
	dispaly_images(mlx_vars);
	move_player(mlx_vars);
	mlx_loop(mlx_vars.mlx);
}
