/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_path_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:13:01 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/08 22:36:55 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_point	get_player(char **map)
{
	int		i;
	int		j;
	t_point	a;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				a.x = i;
				a.y = j;
			}
			j++;
		}
		i++;
	}
	return (a);
}

t_point	get_exit(char **map)
{
	int		i;
	int		j;
	t_point	a;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				a.x = i;
				a.y = j;
			}
			j++;
		}
		i++;
	}
	return (a);
}

int	get_nbr_c(char **map)
{
	int	nbr;
	int	i;
	int	j;

	i = 0;
	nbr = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				nbr++;
			j++;
		}
		i++;
	}
	return (nbr);
}

int	valid_path(char **map, char c, int x, int y)
{
	int	nbr;

	nbr = 0;
	if (map[x][y] == '1')
		return (nbr);
	if (map[x][y] == '0' || map[x][y] == c || map[x][y] == 'P'
		|| map[x][y] == 'C')
	{
		if (map[x][y] == c)
			nbr++;
		map[x][y] = 'X';
		nbr += valid_path(map, c, x + 1, y);
		nbr += valid_path(map, c, x - 1, y);
		nbr += valid_path(map, c, x, y + 1);
		nbr += valid_path(map, c, x, y - 1);
	}
	return (nbr);
}
