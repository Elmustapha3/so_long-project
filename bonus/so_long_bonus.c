/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:59:55 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/08 21:06:09 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_and_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	check_path(char **map, char **map1)
{
	t_point	player;
	int		nbr_c;

	player = get_player(map);
	nbr_c = get_nbr_c(map);
	if (valid_path(map, 'C', player.x, player.y) != nbr_c)
		error_and_exit();
	if (valid_path(map1, 'E', player.x, player.y) != 1)
		error_and_exit();
}

void	check_map(char **map, char *str, char *file)
{
	check_extension_and_content(str, file);
	check_empty_and_nl(str);
	check_rectangle(map);
	check_walls(map);
	check_p_e_c(str);
}

char	**read_map(char **argv, char **str)
{
	int		fd;
	char	**map;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_and_exit();
	while (1)
	{
		tmp = get_next_line(fd);
		*str = ft_strjoin(*str, tmp);
		if (!tmp)
			break ;
		free(tmp);
	}
	map = ft_split(*str, '\n');
	return (map);
}

int	main(int argc, char *argv[])
{
	char	*str;
	t_maps	mps;
	int		i;

	(void)argc;
	mps.map = read_map(argv, &str);
	str[0] = '\0';
	mps.map1 = read_map(argv, &str);
	str[0] = '\0';
	mps.map2 = read_map(argv, &str);
	i = 0;
	check_map(mps.map, str, argv[1]);
	check_path(mps.map, mps.map1);
	window_display(mps.map2);
	return (0);
}
