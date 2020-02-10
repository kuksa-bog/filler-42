/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:00:06 by bkuksa            #+#    #+#             */
/*   Updated: 2019/04/16 21:32:23 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_size_map(t_map *map)
{
	int		k;

	map->i = -1;
	get_next_line(map->fd, &map->line);
	if (map->line && ft_strncmp(map->line, "Plateau", 6) == 0)
	{
		while (map->line[++map->i])
		{
			k = 0;
			while (ft_isdigit(map->line[map->i]) == 1 && map->line[map->i])
			{
				k = k * 10 + (map->line[map->i] - 48);
				map->i++;
			}
			if (map->size_map_y == 0)
				map->size_map_y = k;
			else if (map->size_map_x == 0)
				map->size_map_x = k;
		}
		ft_read_map(map);
	}
}

void	ft_read_map(t_map *map)
{
	ft_strdel(&map->line);
	map->i = 0;
	if (map->map != NULL)
		free(map->map);
	map->map = (char **)malloc(sizeof(char *) * (map->size_map_y));
	get_next_line(map->fd, &map->line);
	ft_strdel(&map->line);
	while (map->i < map->size_map_y)
	{
		get_next_line(map->fd, &map->line);
		map->map[map->i] = ft_strdup(&map->line[4]);
		ft_strdel(&map->line);
		map->i++;
	}
	ft_size_tet(map);
}

void	ft_size_tet(t_map *map)
{
	int		k;

	map->i = -1;
	get_next_line(map->fd, &map->line);
	if (ft_strncmp(map->line, "Piece", 4) == 0)
	{
		while (map->line[++map->i])
		{
			k = 0;
			while (ft_isdigit(map->line[map->i]) == 1 && map->line[map->i])
			{
				k = k * 10 + (map->line[map->i] - 48);
				map->i++;
			}
			if (map->size_tet_y == 0)
				map->size_tet_y = k;
			else if (map->size_tet_x == 0)
				map->size_tet_x = k;
		}
		ft_read_tet(map);
	}
}

void	ft_read_tet(t_map *map)
{
	ft_strdel(&map->line);
	map->i = 0;
	if (map->tet != NULL)
		free(map->tet);
	map->tet = (char **)malloc(sizeof(char *) * (map->size_tet_y));
	while (map->i < map->size_tet_y)
	{
		get_next_line(map->fd, &map->line);
		map->tet[map->i] = ft_strdup(map->line);
		ft_strdel(&map->line);
		map->i++;
	}
}

char	*ft_strjoin_fix(char *s1, char *s2, int n)
{
	char	*s3;

	s3 = NULL;
	if (n == 1)
	{
		s3 = ft_strjoin(s1, s2);
		ft_strdel(&s1);
	}
	if (n == 2)
	{
		s3 = ft_strjoin(s1, s2);
		ft_strdel(&s2);
	}
	if (n == 3)
	{
		s3 = ft_strjoin(s1, s2);
		ft_strdel(&s2);
		ft_strdel(&s1);
	}
	return (s3);
}
