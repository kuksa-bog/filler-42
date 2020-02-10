/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:40:46 by bkuksa            #+#    #+#             */
/*   Updated: 2019/04/25 17:40:48 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_alg2(t_player *pl, t_map *map)
{
	if (pl->g != 0 && pl->g != 1)
	{
		ft_initial_alg(pl, 0);
		ft_alg2_1(pl, map);
		ft_chaos(map, pl, 1);
		if (pl->f != -2 && (pl->g == -1 || pl->f <= pl->g)
													&& (pl->g = pl->f) >= 0)
		{
			pl->x2 = pl->i - pl->xt - map->x;
			pl->y2 = map->i - pl->yt - map->y;
		}
	}
}

void	ft_alg2_1(t_player *pl, t_map *map)
{
	if ((pl->bog == 'X' && ft_error_x(map, pl, pl->yl, pl->xl) > 0)
	|| (pl->bog == 'O' && ft_error_o(map, pl, pl->yl, pl->xl) > 0))
		pl->er1 = 1;
	pl->i1 = -1;
	while (pl->er1 == 0 && ++pl->i1 < map->size_map_y)
	{
		pl->i2 = -1;
		while (++pl->i2 < map->size_map_x)
		{
			if (pl->bog == 'X' && map->map[pl->i1][pl->i2] != 'X')
				pl->er2 = ft_error_x(map, pl, pl->i1, pl->i2);
			else if (pl->bog == 'O' && map->map[pl->i1][pl->i2] != 'O')
				pl->er2 = ft_error_o(map, pl, pl->i1, pl->i2);
			if (pl->er2 == 1
					&& pl->len > ft_distance(pl->yl, pl->xl, pl->i1, pl->i2))
			{
				pl->y0 = pl->i1;
				pl->x0 = pl->i2;
				pl->len = ft_distance(pl->yl, pl->xl, pl->i1, pl->i2);
			}
			pl->er2 = 0;
		}
	}
	pl->y0 = (pl->er1 == 1) ? pl->yl : pl->y0;
	pl->x0 = (pl->er1 == 1) ? pl->xl : pl->x0;
}

int		ft_error_x(t_map *map, t_player *pl, int i1, int i2)
{
	int		i;
	int		j;

	pl->n = 0;
	if (i1 < map->size_map_y && i2 < map->size_map_x
					&& (map->map[i1][i2] == '.' || pl->z1 == -1))
	{
		i = (i1 - 1 < 0) ? i1 : i1 - 1;
		while (i < map->size_map_y && i <= i1 + 1)
		{
			j = (i2 - 1 < 0) ? i2 : i2 - 1;
			while (j < map->size_map_x && j <= i2 + 1)
			{
				if (map->map[i][j] == 'X')
					pl->n++;
				j++;
			}
			i++;
		}
	}
	if (pl->n > 0)
		return (1);
	return (0);
}

int		ft_error_o(t_map *map, t_player *pl, int i1, int i2)
{
	int		i;
	int		j;

	pl->n = 0;
	if (i1 < map->size_map_y && i2 < map->size_map_x
					&& (map->map[i1][i2] == '.' || pl->z1 == -1))
	{
		i = (i1 - 1 < 0) ? i1 : i1 - 1;
		while (i < map->size_map_y && i <= i1 + 1)
		{
			j = (i2 - 1 < 0) ? i2 : i2 - 1;
			while (j < map->size_map_x && j <= i2 + 1)
			{
				if (map->map[i][j] == 'O')
					pl->n++;
				j++;
			}
			i++;
		}
	}
	if (pl->n > 0)
		return (1);
	return (0);
}

int		ft_klon(char *k, int y, int x)
{
	int		i;
	int		y1;
	int		x1;

	i = 0;
	while (k[i])
	{
		y1 = ft_atoi(&k[i]);
		while (ft_isdigit(k[i]) == 1)
			i++;
		i++;
		x1 = ft_atoi(&k[i]);
		if (x == x1 && y == y1)
			return (0);
		while (ft_isdigit(k[i]) == 1)
			i++;
		i++;
	}
	return (1);
}
