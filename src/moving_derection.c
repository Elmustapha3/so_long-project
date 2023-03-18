/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_derection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:26:42 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/08 18:21:17 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(int printer)
{
	ft_printf("%d\nCongratulation, you won!!\n", ++printer);
	exit(0);
}

int	up(t_mlx_vars *m_v, int num_col, int *printer, t_point	p)
{
	if (m_v->map[p.x - 1][p.y] == 'E' && num_col == get_nbr_c(m_v->map))
		win(*printer);
	if (m_v->map[p.x - 1][p.y] != '1' && m_v->map[p.x - 1][p.y] != 'E')
	{
		if (m_v->map[p.x - 1][p.y] == 'C')
		{
			num_col++;
			if (num_col == get_nbr_c(m_v->map))
				open_door(m_v);
			mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.spc,
				50 * p.y, 50 * (p.x - 1));
		}
		m_v->map[p.x - 1][p.y] = 'P';
		m_v->map[p.x][p.y] = '0';
		mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.plyr, 50 * p.y,
			50 * (p.x - 1));
		mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.spc, 50 * p.y,
			50 * p.x);
		ft_printf("%d\n", ++(*printer));
	}
	return (num_col);
}

int	down(t_mlx_vars *m_v, int num_col, int *printer, t_point p)
{
	if (m_v->map[p.x + 1][p.y] == 'E' && num_col == get_nbr_c(m_v->map))
		win(*printer);
	if (m_v->map[p.x + 1][p.y] != '1' && m_v->map[p.x + 1][p.y] != 'E')
	{
		if (m_v->map[p.x + 1][p.y] == 'C')
		{
			num_col++;
			if (num_col == get_nbr_c(m_v->map))
				open_door(m_v);
			mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.spc,
				50 * p.y, 50 * (p.x + 1));
		}
		m_v->map[p.x + 1][p.y] = 'P';
		m_v->map[p.x][p.y] = '0';
		mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.plyr, 50 * p.y,
			50 * (p.x + 1));
		mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.spc, 50 * p.y,
			50 * p.x);
		ft_printf("%d\n", ++(*printer));
	}
	return (num_col);
}

int	left(t_mlx_vars *m_v, int num_col, int *printer, t_point p)
{
	if (m_v->map[p.x][p.y - 1] == 'E' && num_col == get_nbr_c(m_v->map))
		win(*printer);
	if (m_v->map[p.x][p.y - 1] != '1' && m_v->map[p.x][p.y - 1] != 'E')
	{
		if (m_v->map[p.x][p.y - 1] == 'C')
		{
			num_col++;
			if (num_col == get_nbr_c(m_v->map))
				open_door(m_v);
			mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.spc,
				50 * (p.y - 1), 50 * (p.x));
		}
		m_v->map[p.x][p.y - 1] = 'P';
		m_v->map[p.x][p.y] = '0';
		mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.plyr,
			50 * (p.y - 1), 50 * (p.x));
		mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.spc, 50 * p.y,
			50 * p.x);
		ft_printf("%d\n", ++(*printer));
	}
	return (num_col);
}

int	right(t_mlx_vars *m_v, int num_col, int *printer, t_point p)
{
	if (m_v->map[p.x][p.y + 1] == 'E' && num_col == get_nbr_c(m_v->map))
		win(*printer);
	if (m_v->map[p.x][p.y + 1] != '1' && m_v->map[p.x][p.y + 1] != 'E')
	{
		if (m_v->map[p.x][p.y + 1] == 'C')
		{
			num_col++;
			if (num_col == get_nbr_c(m_v->map))
				open_door(m_v);
			mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.spc,
				50 * (p.y + 1), 50 * p.x);
		}
		m_v->map[p.x][p.y + 1] = 'P';
		m_v->map[p.x][p.y] = '0';
		mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.plyr,
			50 * (p.y + 1), 50 * p.x);
		mlx_put_image_to_window(m_v->mlx, m_v->mlx_win, m_v->img.spc, 50 * p.y,
			50 * p.x);
		ft_printf("%d\n", ++(*printer));
	}
	return (num_col);
}
