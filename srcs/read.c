/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:40:08 by efichot           #+#    #+#             */
/*   Updated: 2017/01/06 17:05:39 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		read_pos(int fd, t_env *e)
{
	char	*line;
	int		i;
	char	**line_split;

	line = NULL;
	i = -1;
	if (get_next_line(fd, &line) < 1)
		error_map();
	line_split = ft_strsplit(line, ' ');
	while (line_split[++i])
		;
	if (i != 4)
		error_map();
	e->map_width = ft_atoi(line_split[0]);
	e->map_height = ft_atoi(line_split[1]);
	e->player.pos.x = ft_atoi(line_split[2]) + 0.5;
	e->player.pos.y = ft_atoi(line_split[3]) + 0.5;
	if (e->map_width < 0 || e->map_height < 0 || e->player.pos.x < 0 ||
		e->player.pos.y < 0 || e->player.pos.x >= e->map_width ||
		e->player.pos.y >= e->map_height)
		error_map();
	return (1);
}

int		read_line(char *line, int y, int **map, t_env *e)
{
	int		x;
	char	**line_split;

	x = -1;
	if (y >= e->map_height)
		error_map();
	line_split = ft_strsplit(line, ' ');
	if (!(map[y] = (int *)malloc(sizeof(int) * e->map_width)))
		return (0);
	while (line_split[++x])
	{
		if (ft_atoi(line_split[x]) > 1 || ft_atoi(line_split[x]) < 0 ||
		x > e->map_width)
			error_map();
		map[y][x] = ft_atoi(line_split[x]);
	}
	if (x != e->map_width)
		error_map();
	return (1);
}

int		read_file(int fd, t_env *e)
{
	char	*line;
	int		y;
	int		**map;

	y = -1;
	line = NULL;
	if (!read_pos(fd, e))
		return (0);
	if (!(map = (int **)malloc(sizeof(int *) * e->map_height)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(read_line(line, ++y, map, e)))
			return (0);
	}
	if (map[(int)e->player.pos.y][(int)e->player.pos.x] != 0)
		error_map();
	e->map = map;
	return (1);
}

int		open_file(t_env *e, char *file)
{
	int		fd;

	if (open(file, O_DIRECTORY) >= 0)
		return (0);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	return (read_file(fd, e));
}
