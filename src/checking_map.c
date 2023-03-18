/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 03:11:17 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/15 04:37:23 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension_and_content(char *str, char *file)
{
	int	i;

	i = ft_strlen(file);
	i--;
	if (file[i--] != 'r' || file[i--] != 'e' || file[i--] != 'b'
		|| file[i--] != '.')
		error_and_exit();
	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'P' && str[i] != 'E'
			&& str[i] != 'C' && str[i] != 10)
			error_and_exit();
		i++;
	}
}

void	check_rectangle(char **map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			error_and_exit();
		i++;
	}
}

void	check_walls(char **map)
{
	int	lenc;
	int	len;
	int	i;
	int	j;

	lenc = 0;
	while (map[lenc])
		lenc++;
	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == lenc - 1) && map[i][j] != '1')
				error_and_exit();
			if ((j == 0 || j == len - 1) && map[i][j] != '1')
				error_and_exit();
			j++;
		}
		i++;
	}
}

void	check_p_e_c(char *str)
{
	int	i;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			p++;
		if (str[i] == 'E')
			e++;
		if (str[i] == 'C')
			c++;
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		error_and_exit();
}

void	check_empty_and_nl(char *str)
{
	int	i;

	if (str[0] == 10 || str[0] == '\0')
		error_and_exit();
	i = 0;
	while (str[i])
	{
		if (str[i] == 10 && str[i + 1] == 10)
			error_and_exit();
		i++;
	}
}
