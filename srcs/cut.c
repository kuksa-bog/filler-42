/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:23:19 by bkuksa            #+#    #+#             */
/*   Updated: 2019/05/13 10:57:36 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_cut(t_map *map, t_player *pl)
{
	int		x2;
	int		y2;

	x2 = -1;
	y2 = -1;
	map->i = -1;
	while (++map->i < map->size_tet_y)
	{
		pl->i = -1;
		while (++pl->i < map->size_tet_x)
		{
			if (map->tet[map->i][pl->i] == '*')
			{
				map->x = (pl->i < map->x || map->x == -1) ? pl->i : map->x;
				x2 = (pl->i > x2 || x2 == -1) ? pl->i : x2;
				map->y = (map->i < map->y || map->y == -1) ? map->i : map->y;
				y2 = (map->i > y2 || y2 == -1) ? map->i : y2;
			}
		}
	}
	pl->tet1 = (map->y != y2) ? y2 - map->y + 1 : 1;
	pl->tet2 = (map->x != x2) ? x2 - map->x + 1 : 1;
	if (map->y != -1)
		ft_cut2(map, pl);
}

void	ft_cut2(t_map *map, t_player *pl)
{
	char	**cut;
	int		x1;
	int		y1;
	int		i;
	int		j;

	i = 0;
	map->i = map->y - 1;
	y1 = pl->tet1 + 1;
	cut = (char **)malloc(sizeof(char *) * (pl->tet1));
	while (++map->i < map->size_tet_y && --y1)
	{
		j = 0;
		pl->i = map->x - 1;
		x1 = pl->tet2 + 1;
		cut[i] = (char *)malloc(sizeof(char) * (pl->tet2));
		while (++pl->i < map->size_tet_x && --x1 > 0)
		{
			cut[i][j] = map->tet[map->i][pl->i];
			j++;
		}
		cut[i][j] = '\0';
		i++;
	}
	ft_free2(map, cut, pl);
}

void	ft_free2(t_map *map, char **s, t_player *pl)
{
	int		i;

	i = 0;
	while (i < map->size_tet_y && map->tet[i] != NULL)
	{
		free(map->tet[i]);
		i++;
	}
	free(map->tet);
	map->tet = s;
	map->size_tet_y = pl->tet1;
	map->size_tet_x = pl->tet2;
	map->i = 0;
	pl->tet1 = -1;
	pl->tet2 = -1;
	ft_boundar(map, pl);
}

void	ft_boundar(t_map *map, t_player *pl)
{
	map->i = 0;
	while (map->i < map->size_map_y && map->tet[0] != NULL)
	{
		pl->i = 0;
		while (pl->i < map->size_map_x)
		{
			if (map->map[map->i][pl->i] == pl->bog)
			{
				pl->tet1 = (pl->tet1 == -1 || pl->tet1 > map->i)
											? map->i : pl->tet1;
				pl->tet2 = (pl->tet2 == -1 || pl->tet2 < map->i)
											? map->i : pl->tet2;
			}
			pl->i++;
		}
		map->i++;
	}
}

void	ft_start_alg(t_player *pl, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (pl->a5 == -1 && (i = map->size_map_y / 4))
		j = map->size_map_x / 5;
	if (pl->a5 == -2 && (i = map->size_map_y / 4))
		j = (map->size_map_x / 5) * 4;
	if (pl->a5 == -3 && (i = (map->size_map_y / 4) * 4))
		j = map->size_map_x / 5;
	if (pl->a5 == -4 && (i = (map->size_map_y / 4) * 4))
		j = (map->size_map_x / 5) * 4;
	if (ft_distance(i, j, pl->yl, pl->xl) < pl->k1)
	{
		pl->k1 = ft_distance(i, j, pl->yl, pl->xl);
		pl->x = pl->i - pl->xt - map->x;
		pl->y = map->i - pl->yt - map->y;
	}
}
